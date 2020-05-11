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

int n, m;

bool check(int mat[][50], int i, int j) {
    if(i+1 >= n || j+1 >= m)
        return 0;
    else {
        if(mat[i][j] == 1 && mat[i][j+1] == 1 && mat[i+1][j] == 1 && mat[i+1][j+1] == 1)
            return 1;
        else 
            return 0;
    }
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mat[50][50];
    vector<pair<int, int>> result;
    bool bit = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                bool a = check(mat, i, j), b = check(mat, i-1, j-1), c = check(mat, i-1, j), d = check(mat, i, j-1);
                if(a || b || c || d) {
                    if(a == 1)
                        result.pb(mp(i, j));
                }
                else {
                    bit = 0;
                    break;
                }
            }
        }
        if(bit == 0)    break;
    }
    if(bit == 0)
        cout << -1;
    else {
        cout << result.size() << "\n";
        for(int i = 0; i < (int)result.size(); i++)
            cout << result[i].ff + 1 << " " << result[i].ss + 1 << "\n";
    }
    return 0;
}


