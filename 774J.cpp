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
int n, k;
int memo[101][101][101];

// Memoization based Soution
int solve(string &str, int i, int N, int _max) {
    _max = max(N, _max);
    int &a = memo[i][N][_max];  
    if(a != -1) return a;
    if(i == n)  return a = (_max == k);
    if(str[i] != 'N') {
        bool temp1 = solve(str, i+1, 0, _max);
        if(str[i] == 'Y' || temp1)   return a = temp1;
    }
    return a = solve(str, i+1, N+1, _max);
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    string str; cin >> str;
    cout << (solve(str, 0, 0, 0)? "YES": "NO");  
    return 0;
}


