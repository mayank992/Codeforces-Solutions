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
    ll state[100001];
    state[0] = 0;
    int n, count = 0, arr[100001];;
    cin >> n;
    arr[n] = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vector<pair<int, int>> vec;
    vec.pb(mp(0, 0));
    for(int i = 0; i < n; i++) {
        count++;
        if(arr[i] != arr[i+1]) {
            vec.pb(mp(arr[i], count));
            count = 0;
        }
    }
    state[1] = (ll )vec[1].ff * vec[1].ss;
    for(int i = 2; i < vec.size(); i++) {
        ll temp = (ll)vec[i].ff * vec[i].ss;
        if(vec[i].ff - 1 == vec[i-1].ff)
            state[i] = max(state[i-1], state[i-2] + temp);
        else 
            state[i] = state[i-1] + temp;
    }
    cout << state[vec.size() - 1];
    return 0;
}


