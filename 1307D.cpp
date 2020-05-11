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
int N;

vector<int> graph[200001];
map<int, bool> isSpecial;

int bfs(int source, int source_Dist[]) {
    int result = 0;
    bool Vis[N+1] = {0};
    queue<pair<int, int>> q;
    Vis[source] = 1; 
    q.push(mp(source, 0));
    while(!q.empty()) {
        pair<int, int> front = q.front();
        if(isSpecial[front.ff]) source_Dist[front.ff] = front.ss;
        q.pop();
        if(front.ff == N)   result = front.ss;
        for(auto i: graph[front.ff]) {
            if(!Vis[i]) {
                Vis[i] = 1;
                q.push(mp(i, front.ss + 1));
            }
        }
    }
    return result;
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int source_Dist[200001] = {0}, dest_Dist[200001] = {0};
    int m, k, u, v, temp, bit = 0;
    cin >> m >> k;
    for(int i = 0; i < k; i++) {
       cin >> temp;
       isSpecial[temp] = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if(bit == 0) {
            if(isSpecial[u] && isSpecial[v])
                bit = 1;
        }
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int backup = bfs(1, source_Dist);
    if(bit == 1) {
        cout << backup;
        return 0;
    }
    bfs(N, dest_Dist);
    
    return 0;
}


