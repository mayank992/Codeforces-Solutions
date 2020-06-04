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
const int N    =  1e7 + 1;

// /* 
// if (vertex == 0): then on vertex other than D
// else:    on vertex D which is destination
// */
// int memo[2][N];
// ll solve(bool vertex, int steps) {
//     if (steps == 0)
//         return vertex;
//     ll ways = 0;
//     /* 
//     cases:
//     case1. currently on vertex D(vertex = 1) and moving towards vertexs other than D.
//     case2. currently on vertex {A, B, C}(vertex = 0) and moving towards vertex D.
//     */
//     int &res = memo[vertex][steps];
//     if (res != -1)
//         return res;
//     if (vertex == 1)
//         return res = (3 * solve(0, steps - 1)) % MOD;
//     else
//         return res = ((2 * solve(0, steps - 1)) + solve(1, steps - 1)) % MOD;
// }
int dp[2][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //memset(memo, -1, sizeof(memo));
    int steps;
    cin >> steps;
    //cout << solve(1, steps) << "\n";    
    dp[0][0] = 0, dp[1][0] = 1;
    for (int i = 1; i <= steps; i++) {
        // case2 (vertex = 0)
        dp[0][i] = ((2LL * dp[0][i - 1]) + dp[1][i - 1]) % MOD;
        // case2 (vertex = 1)
        dp[1][i] = (3LL * dp[0][i - 1]) % MOD;
    }
    cout << dp[1][steps];
    return 0;
}