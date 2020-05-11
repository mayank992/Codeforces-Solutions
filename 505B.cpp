#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

class DisjSet {
    public:
        int parent[100], n;
        DisjSet() {
            memset(parent, -1, sizeof(parent));
        }
        int _find(int x) {
            // Path compression
            if(parent[x] >= 0)
                parent[x] = _find(parent[x]);
            else 
                return x; 
            return parent[x];
        }
        void _union(int x, int y) {
            int parent_x = _find(x);
            int parent_y = _find(y);
            if(parent_x == parent_y)
                return ;
            if(parent_x < parent_y)
                parent[parent_y] = parent_x;
            else   
                parent[parent_x] = parent_y;
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DisjSet ds[100];
    int n, m, u, v, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        // if(ds[c-1].parent[u-1] == -1)   ds[c-1].parent[u-1] = u-1;
        // if(ds[c-1].parent[v-1] == -1)   ds[c-1].parent[v-1] = v-1;
        ds[c-1]._union(u-1, v-1);
    }    
    int q;
    cin >> q;
    while(q--) {
        int result = 0;
        cin >> u >> v;
        for(int i = 0; i < 100; i++) {
            if(ds[i]._find(u-1) == ds[i]._find(v-1))
                result += 1;
        }
        cout << result << "\n";
    }
    return 0;
}


