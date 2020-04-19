#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop1 pop_back
#define mp make_pair
#define MAX 1000
#define Invalid 10000000 
#define Fi first
#define Se second
#define ALL(v)  v.begin(), v.end()

class Item{
    public:
        int row, col, dist;
    Item(int row, int col, int dist) {
        this -> row = row;
        this -> col = col;
        this -> dist = dist;
    }
};

//  1 for return cur.dist, 2 for continue, 3 for result += cur.dist
int work(char forest[MAX][MAX], Item cur, int minDistSE, int opr) {
    if(opr == 0) {
        if(forest[cur.row][cur.col] == 'E')
            return 1;
    }
    else {
        if(cur.dist > minDistSE)
            return 2;
        if(forest[cur.row][cur.col] >= '1' && forest[cur.row][cur.col] <= '9')  
            return 3;
    }
    return 0;
}

bool isValid(char forest[MAX][MAX], bool Vis[MAX][MAX], pair<int, int> cur, int r, int c) {
    if(cur.Fi < 0 || cur.Fi >= r || cur.Se < 0 || cur.Se >= c || forest[cur.Fi][cur.Se] == 'T' || Vis[cur.Fi][cur.Se])
        return 0;
    return 1;
}

int bfs(char forest[MAX][MAX], pair<int, int> S, int r, int c, int minDistSE, int opr) {
    bool Vis[MAX][MAX] = {0};
    queue<Item> q;
    q.push(Item(S.Fi, S.Se, 0));
    Vis[S.Fi][S.Se] = true;
    int result = 0;
    while(!q.empty()) {
        Item cur = q.front();
        q.pop();    
        //**************************************************
        int res = work(forest, cur, minDistSE, opr);
        if(res == 1)
            return cur.dist;
        else if(res == 2)
            continue;
        else if(res == 3)
            result += (int )forest[cur.row][cur.col] - '0';
        //**************************************************
        if(isValid(forest, Vis, {cur.row, cur.col - 1}, r, c)) {
            Vis[cur.row][cur.col - 1] = true;
            q.push(Item(cur.row, cur.col - 1, cur.dist + 1));
        }
        if(isValid(forest, Vis, {cur.row, cur.col + 1}, r, c)) {
            Vis[cur.row][cur.col + 1] = true;
            q.push(Item(cur.row, cur.col + 1, cur.dist + 1));
        }
        if(isValid(forest, Vis, {cur.row - 1, cur.col}, r, c)) {
            Vis[cur.row - 1][cur.col] = true;
            q.push(Item(cur.row - 1, cur.col, cur.dist + 1));
        }
        if(isValid(forest, Vis, {cur.row + 1, cur.col}, r, c)) {
            Vis[cur.row + 1][cur.col] = true;
            q.push(Item(cur.row + 1, cur.col, cur.dist + 1));
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char forest[MAX][MAX];  pair<int, int > S, E;
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> forest[i][j];
            if(forest[i][j] == 'S') 
                S.first = i, S.second = j;
            if(forest[i][j] == 'E')
                E.first = i, E.second = j;
        }
    } 
    int minDistSE = 0;
    minDistSE = bfs(forest, S, r, c, minDistSE, 0);
    int count = bfs(forest, E, r, c, minDistSE, 1);
    cout << count << "\n";
    return 0;
}


