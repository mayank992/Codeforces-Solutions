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

int dp[101][2];
int d, k;

ll solve(int n, bool inc) {
    if(n < 0)
        return 0;
    if(n == 0) 
        return ((inc == 1)? 1: 0);
    if(dp[n][inc] != -1)    return dp[n][inc];
    ll result = 0;
    for(int i = 1; i <= k; i++) {
        result = (result + solve(n-i, (i >= d) || inc)) % MOD;
    }
    return dp[n][inc] = result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> k >> d; 
    cout << solve(n, 0);
    return 0;
}


