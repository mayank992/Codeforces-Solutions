#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define mem(a,v) memset(a, v, sizeof(a))
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
#define umap	 unordered_map
#define pii	     pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 1; i < n; i++) 
        arr[i] += arr[i - 1];
    ll res[n + 1]; mem(res, 0);
    for (int k = 0; k < n; k++) {
        res[k] = arr[k];
        if (k - m >= 0)
            res[k] += res[k - m];
        cout << res[k] << " ";
    }   
    return 0;
}

