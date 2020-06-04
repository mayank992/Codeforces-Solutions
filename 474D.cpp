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
const int N    =  1e5 + 2;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    cin >> t >> k;
    int dp[N] = {1};
    for (int i = 1; i <= 100000; i++) {
        if (i - k >= 0)
            dp[i] = dp[i - k] % MOD;
        dp[i] = ((ll )dp[i] + dp[i - 1]) % MOD;
    }
    for (int i = 1; i <= 100000; i++) {
        dp[i] = ((1LL * dp[i]) + dp[i - 1]) % MOD;
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        ll result = dp[b] - dp[a - 1];
        result += MOD;  result %= MOD;
        cout << result << "\n"; 
    }
    return 0;
}


