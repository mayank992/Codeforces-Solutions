#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()
pair<int, bool> dp[6][6];
//Bottom-up Dynamic programming
void solve(string &str, int n) {
    for(int i = 0; i < n-1; i++) {
        dp[i+1][i].second = true;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(i == j)
                dp[i][j].first = dp[i][j].second = 1;
            else {
                dp[i][j].first = dp[i][j-1].first + dp[i+1][j].first - dp[i+1][j-1].first;
                if(str[i] == str[j] && dp[i+1][j-1].second) {
                    dp[i][j].first += 1;
                    dp[i][j].second = true;
                }
                else {
                    dp[i][j].second = false;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int q;
    cin >> str;
    solve(str, str.length());
    for(int i = 0; i < str.length(); i++) {
        for(int j = 0; j < str.length(); j++) {
            cout << dp[i][j].first << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i < str.length(); i++) {
        for(int j = 0; j < str.length(); j++) {
            cout << dp[i][j].second << " ";
        }
        cout << "\n";
    }
    cin >> q;
    while(q--) {
        int i, j;
        cin >> i >> j;
        if(i == j)
            cout << 1 << "\n";
        else 
            cout << dp[i-1][j-1].first << "\n";
    }
    return 0;
}
