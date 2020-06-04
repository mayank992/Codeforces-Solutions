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
const int N    =  200001;
struct d{
    ll a; int b, c;
    d& operator +=(const d& temp) {
        a += temp.a;    b += temp.b;    c += temp.c;
    }
};
vector<d> vec;
vector<int> g[N];

d dfs(int u, int parent, ll minCost) {
    d result = {0, 0, 0};
    if (vec[u].b != vec[u].c)
        ((vec[u].b == 0)?  result.b: result.c) += 1;
    for (int v: g[u]) {
        if (v == parent)    continue;
        result += dfs(v, u, min(minCost, vec[u].a));
    }
    if (vec[u].a < minCost) {
        ll count = min(result.b, result.c);
        d temp = {(2LL * vec[u].a * count), -count, -count};
        result += temp;
    }
    return result;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  d temp; 
    cin >> n;
    vec.pb(temp);
    for (int i = 0; i < n; i++) {
        cin >> temp.a >> temp.b >> temp.c;
        vec.pb(temp); 
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;   cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    d result = dfs(1, 0, INT_MAX);
    if (result.b != 0 || result.c != 0)
        cout << -1 << "\n";
    else 
        cout << result.a << "\n";
    return 0;
}
