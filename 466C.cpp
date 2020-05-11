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

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n), count(n, 0);
    ll sum = 0, cur_sum = 0, result = 0;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }    
    if(sum % 3) {
        cout << 0;
        return 0;
    }
    sum /= 3;
    for(int i = 0; i < n; i++) {
        cur_sum += vec[i];
        if(cur_sum == sum)
            count[i] += 1;
        if(i > 0)   count[i] += count[i-1];
    }
    cur_sum = 0;
    for(int i = n-1; i > 1; i--) {
        cur_sum += vec[i];
        if(cur_sum == sum)
            result += count[i-2];
    }
    cout << result;
    return 0;
}


