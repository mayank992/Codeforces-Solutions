#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
#define umap	 unordered_map
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;
vector<ll> height(30000);
ll k, n;

bool is_possible(ll mid) {
    ll rows = 0, i = 0;
    vector<ll> temp(n, 0);
    temp[0] = height[0];
    while(i < n && rows < k) {
        if(temp[i] >= mid) {
            rows += temp[i] / mid;
            temp[i] = temp[i] % mid;
        }
        else {
            if(i + 1 < n && temp[i] + height[i+1] >= mid) {
                rows += (temp[i] + height[i+1]) / mid;
                temp[i+1] = (temp[i] + height[i+1]) % mid;
            }
            else if(i + 1 < n)
                temp[i+1] = height[i+1];
            i++;
        }
    }
    return ((rows >= k)? 1: 0);
}

ll solve() {
    ll sum = 0, low = 0, high, result = 0;
    for(int i = 0; i < n; i++)
        sum += height[i];
    high = sum / k;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(is_possible(mid)) {
            result = max(result, mid);
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> height[i];
        cout << solve() * k << "\n";
    }   
    return 0;
}


