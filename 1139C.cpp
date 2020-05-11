#include <bits/stdc++.h>
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
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;
//dsu based soln
class DisjSet
{
public:
    int *parent, *count, n;
    DisjSet(int n)
    {
        parent = new int[n]{0};
        count = new int[n]{0};
        memset(parent, -1, n * sizeof(int));
        this->n = n;
    }
    int _find(int x)
    {
        if (parent[x] >= 0)
        {
            parent[x] = _find(parent[x]);
        }
        else
            return x;
        return parent[x];
    }
    void _union(int x, int y)
    {
        int parent_x = _find(x);
        int parent_y = _find(y);
        if (parent_x == parent_y)
            return;
        if (parent_x < parent_y)
        {
            parent[parent_y] = parent_x;
            count[parent_x] += count[parent_y];
        }
        else
        {
            parent[parent_x] = parent_y;
            count[parent_y] += count[parent_x];
        }
    }
};

ll mfast_pow(ll base, ll power, ll mod)
{
    ll result = 1;
    while (power > 0)
    {
        if (power & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, u, v, c;
    cin >> n >> k;
    DisjSet ds(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> c;
        if (c == 0)
        {
            if (ds.count[u - 1] == 0)
                ds.count[u - 1] = 1;
            if (ds.count[v - 1] == 0)
                ds.count[v - 1] = 1;
            ds._union(u - 1, v - 1);
        }
    }
    unordered_map<int, int> mappy;
    vector<int> count;
    for (int i = 0; i < n; i++)
    {
        int parent = ds._find(i);
        if (ds.count[parent] != 0 && mappy[parent] == 0)
        {
            mappy[parent] = 1;
            count.pb(ds.count[parent]);
        }
    }
    ll result = mfast_pow(n, k, MOD) - n;
    for (int i = 0; i < count.size(); i++)
    {
        ll res = mfast_pow(count[i], k, MOD) - count[i];
        result -= res;
        result += MOD;
        result %= MOD;
    }
    cout << result % MOD;
    return 0;
}

// dfs based soln
// vector<int> adj[100000];
// int Vis[100000] = {0};
// int _count;

// void dfs(int s) {
//     if(Vis[s])  return ;
//     Vis[s] = 1;
//     _count += 1;
//     for(auto u: adj[s]) {
//         dfs(u);
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, k, u, v, c;
//     cin >> n >> k;
//     ll ans = mfast_pow(n, k, MOD) - n;
//     for(int i = 0; i < n-1; i++) {
//         cin >> u >> v >> c; u--, v--;
//         if(c == 0) {
//             adj[u].pb(v);
//             adj[v].pb(u);
//         }
//     }
//     for(int i = 0; i < n; i++) {
//         _count = 0;
//         if(adj[i].size())
//             dfs(i);
//         ll res = mfast_pow(_count, k, MOD) - _count;
//         ans -= res;
//         ans += MOD;
//         ans = ans % MOD;
//     }
//     cout << ans;
//     return 0;
// }
