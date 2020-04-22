#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int _find(int parent[], int x) {
    if(parent[x] < x && parent[x] >= 0)
        parent[x] = _find(parent, parent[x]);
    else 
        return x;
    return parent[x];
}
 
void _union(int parent[], int x, int y) {
    int parent_x = _find(parent, x);
    int parent_y = _find(parent, y);
    if(parent_x == parent_y)
        return ;
    if(parent_x < parent_y)
        parent[parent_y] = parent_x;
    else 
        parent[parent_x] = parent_y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int parent[100];
    memset(parent, -1, sizeof(parent));
    int n, m, emp = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int  l, prev = -1, lang;
        cin >> l;
        if(l == 0)  emp++;
        for(int j = 0; j < l; j++) {
            cin >> lang;    lang--;
            if(j == 0 && parent[lang] == -1)
                parent[lang] = lang;
            if(j > 0)
                _union(parent, prev, lang);
            prev = lang;
        }
    }       
    set<int> result;
    for(int i = 0; i < m; i++) {
        if(parent[i] != -1)
            result.insert(_find(parent, i));
    }
    cout << emp + ((result.size() == 0)? 0: (result.size() - 1));
    return 0;
}


