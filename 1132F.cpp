#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int _min(int a, int b, int c) {
    return min(a, min(b, c));
}

void solve(string &str, int n) {
    int dp[501][501] = {0};
    for(int i = 1; i <= n; i++)
        dp[i][i] = 1; 
    for(int k = 2; k <= n; k++) {
        for(int i = 1, j = k; j <= n; i++, j++) {
            dp[i][j] = dp[i][j-1] + 1;
            for(int c = j-1; c >= i; c--) {
                if(str[c-1] == str[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i][c] + dp[c+1][j-1]);
                }
            }
        }
    }   
    cout << dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    solve(str, n);    
    return 0;
}


