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

vector<int> part;

int solve(string &str, int n) {
    int dp[n] = {0}, P[n][n] = {0};
    for(int i = 0; i < n; i++) {
        P[i][i] = 1;
        if(i+1 < n) P[i+1][i] = 1;
    }
    for(int k = 1; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(str[i] == str[j] && P[i+1][j-1])
                P[i][j] = 1;
            else 
                P[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(P[0][1])
            dp[i] = 0;
        else {
            dp[i] = INT_MAX;
            part.pb(-1);
            for(int j = 0; j < i; j++) {
                if(P[j+1][i] && dp[i] > dp[j] + 1) {
                    part[part.size()-1] = j+1;
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    return dp[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int k;
    cin >> str;
    cin >> k;
    int res = solve(str, str.length());
    if(res > 0) {
        cout << res;
        int idx = 0;
        for(int i = 0; i < str.length(); i++) {
            if(part[idx] == i)  cout << '+';
            cout << str[i];
        }
        cout << "\n";
    }
    else {
        cout << 0 << "\n";
        cout << str;
    }
    return 0;
}


