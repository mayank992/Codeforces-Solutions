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
    int t;
    cin >> t;
    while (t--) {
        int n;  cin >> n;
        bool mt[2][n];  pii m[2][n + 1];
        char ch;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ch;
                if (ch == '1' || ch == '2')
                    mt[i][j] = 0;
                else 
                    mt[i][j] = 1;
            }
        }
        mem(m, 0);
        m[0][0] = {1, 0};
        m[1][0] = {0, 0};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                if (mt[j][i - 1] == 0) {
                    if (m[j][i - 1].ff == 1)
                        m[j][i].ff = !mt[j][i - 1];
                }
                else {
                    if (j == 0) {
                        if (m[j][i - 1].ff == 1)
                            m[j][i].ss = 1;
                        else if (m[1][i - 1].ff == 1 && mt[1][i - 1] == 1) 
                            m[1][i].ss = m[j][i].ff = 1;
                    }
                    else 
                        m[j][i].ff = m[0][i].ss;
                }
            }
        }
        if (m[1][n].ff == 1)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }    
    return 0;
}

