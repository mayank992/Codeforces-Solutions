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
    int n;
    cin >> n;   
    int cost[n];    string str[n + 1][2];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    str[0][0] = str[0][1] = "\0";   
    for (int i = 1; i <= n; i++) {
        cin >> str[i][0];
        str[i][1] = str[i][0];
        reverse(all(str[i][1]));
    }
    ll dp[n + 1][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            dp[i][j] = LLONG_MAX;
            if (str[i - 1][0] <= str[i][j])
                dp[i][j] = dp[i - 1][0];
            if (str[i - 1][1] <= str[i][j]) 
                dp[i][j] = min(dp[i][j], dp[i - 1][1]);
            if (j == 1 && dp[i][j] != LLONG_MAX)
                dp[i][j] += cost[i - 1];      
        }   
    }
    ll result = min(dp[n][0], dp[n][1]);
    if (result == LLONG_MAX)
        cout << -1 << "\n";
    else    
        cout << result << "\n";
    return 0;
}

