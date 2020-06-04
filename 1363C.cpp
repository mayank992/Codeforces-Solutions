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

bool Vis[1001];
int dfs(vector<int> g[], int src, int parent) {
    Vis[src] = 1;
    int count = 0;
    for (int u: g[src]) {
        if (!Vis[u] && u != parent)
            count += dfs(g, u, src);
    }
    return count + 1;
}

int solve() {
    mem(Vis, 0);
    vector<int> g[1001];
    int n, x;   cin >> n >> x;
    for (int i = 0; i < n - 1; i++) {
        int u, v;   cin >> u >> v;
        g[u].pb(v); g[v].pb(u);    
    }
    if (g[x].size() <= 1)
        return 1;
    else {
        int count = 0;
        for (int u: g[x]) {
            count += dfs(g, u, x) - 1;
        }
        int connected_edges_to_x = g[x].size();
        if (count & 1)  // Ashish's turn
            return ((connected_edges_to_x & 1)? 0: 1);
        else    // Ayush's turn
            return ((connected_edges_to_x & 1)? 1: 0);
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        if (solve()) 
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
    }    
    return 0;
}
