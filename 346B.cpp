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

bool check(string &str, string &virus) {
    int i = str.size() - 1, j = virus.size() - 1;
    while(i >= 0 && j >= 0 && str[i] == virus[j])
        i--, j--;
    if(j == -1) return 0;
    else    return 1;
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string a, b, virus;
    cin >> a >> b >> virus;
    vector<string> vec; vec.pb("");
    pair<int, int> dp[101][101];
    memset(dp, 0, sizeof(dp));
    n = a.length(), m = b.length();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                string temp = vec[dp[i-1][j-1].ss] + a[i-1];
                if(check(temp, virus)) {
                    vec.pb(temp);
                    dp[i][j].ss = vec.size()-1;
                    dp[i][j].ff = dp[i-1][j-1].ff + 1;
                }
                else 
                    dp[i][j] = dp[i-1][j-1];
            }
            else {
                if(dp[i][j-1].ff > dp[i-1][j].ff)
                    dp[i][j] = dp[i][j-1];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(vec[dp[n][m].ss] == "")
        cout << 0;
    else 
        cout << vec[dp[n][m].ss];
    return 0;
}


