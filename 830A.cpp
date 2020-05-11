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

int solve(int pos[], int keys[], int n, int k) {
    int l = 0, h = 
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, p, pos[1000], keys[2000];
    cin >> n >> k >> p;
    for(int i = 0; i < n; i++)
        cin >> pos[i];
    for(int i = 0; i < k; i++)
        cin >> keys[i];
    sort(pos, pos + n);
    sort(keys, keys + k);
    cout << solve(pos, keys, n , k) << "\n";
    return 0;
}


