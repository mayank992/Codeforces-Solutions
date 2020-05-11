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
        int *parent, n;

        DisjSet(int n) {
            parent = new int[n]{0};
            memset(parent, -1, n * sizeof(int));
            this -> n = n;
        }
        int _find(int x) {
            // Path compression
            if(parent[x] < x && parent[x] >= 0)
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
    int n, m;
    ll result = 0;
    cin >> n >> m;
    DisjSet ds(n);
    if(m == 0) {
        cout << 1;
        return 0;
    }
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        ds._union(x-1, y-1);
    }
    set<int> s;
    for(int i = 0; i < n; i++) {
        if(ds.parent[i] != -1)
            result++;
    }
    result = pow(2, result);
    cout << result;
    return 0;
}