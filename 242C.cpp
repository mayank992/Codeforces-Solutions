#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define limit 1000000000
#define pb push_back
#define pop1 pop_back
#define mp make_pair
#define umap unordered_map
#define ALL(v)  v.begin(), v.end()

class Move{
    public:
        int i, j, minDist;
    Move(int a, int b, int c): i(a), j(b), minDist(c) {}
};

bool bfs(map<pair<int, int>, bool> &Board, pair<int, int> S, pair<int, int> D) {
    map<pair<int, int>, bool> Vis;
    Vis[{S.first, S.second}] = 1;
    queue<Move> q;
    q.push(Move(S.first, S.second, 0)); 
    while(!q.empty()) {
        Move front = q.front();
        q.pop();
        if(front.i == D.first && front.j == D.second) {
            cout << front.minDist;
            return 1;
        }
        int i = front.i, j = front.j, D = front.minDist + 1; 
        for(int u = i-1; u <= i+1; u++) {
            for(int v = j-1; v <= j+1; v++) {
                if((u == i && v == j) || u < 1 || v < 1 || u > limit || v > limit || Vis[{u, v}] || !Board[{u, v}]) 
                    continue;
                Vis[{u, v}] = 1;
                q.push(Move(u, v, D));
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c1, c2;
    map<pair<int, int>, bool> Board;
    pair<int, int> S, D;
    cin >> S.first >> S.second >> D.first >> D.second;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> r >> c1 >> c2;
        for(int c = c1; c <= c2; c++)  
            Board[{r, c}] = 1;
    }
    bool exist = bfs(Board, S, D);
    if(!exist)
        cout << -1;
    return 0;
}


