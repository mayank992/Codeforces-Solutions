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
const ll INF   =  1e15;
int m;

// ll memo[5001][5001];
// ll solve(ll pref[], int n, int k) {
//     if (n == 0 || k == 0)   return 0;
//     if (memo[n][k] != -1)
//         return memo[n][k]; 
//     ll res1 = -INF, res2 = -INF;
//     // selecting the segment of size m
//     if (n - m >= 0)
//         res1 = solve(pref, n - m, k - 1) + (pref[n] - pref[n - m]);
//     // discarding current element
//     res2 = solve(pref, n - 1, k);
//     return memo[n][k] = max(res1, res2);
// }

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //mem(memo, -1);
    int n, k;
    cin >> n >> m >> k;
    int arr[n]; ll pref[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pref[0] = 0; pref[1] = arr[0];
    for (int i = 2; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i - 1];
    // Bottom-up DP
    ll dp[n + 1][k + 1];
    mem(dp, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = -INF;
            if (i - m >= 0)
                dp[i][j] = dp[i - m][j - 1] + (pref[i] - pref[i - m]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}

