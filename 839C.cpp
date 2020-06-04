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
const int N = 1e5 + 1;
vector<int> g[N];

double dfs(int u, int parent) {
    double result = 0;
    for (int v: g[u]) {
        if (v == parent)    continue;
        result += dfs(v, u);
    }
    int temp = g[u].size();
    if (temp != 1)
        result = result / (temp - 1);
    return result + 1;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;   cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }   
    double result = 0;
    for (int u: g[1])
        result += dfs(u, 1);
    if (n != 1)
        result = result / (int )g[1].size();
    cout << ps(result, 15) << "\n";
    return 0;
}

