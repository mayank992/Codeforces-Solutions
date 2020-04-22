#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define popb pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

bool isValid(int wall, int height, map<pair<bool, int>, bool> &Vis, string &left, string &right) {
    if(height < 0 || Vis[{wall, height}])
        return 0;
    if(height < left.length()){
        if((wall == 0 && left[height] == 'X') || (wall == 1 && right[height] == 'X'))
            return 0;
    }
    Vis[{wall, height}] = 1;
    return 1;    
}

bool bfs(string &left, string &right, int k, int n) {
    map<pair<bool, int>, bool> Vis;
    int level, wall, height;
    Vis[{0, 0}] = 1;
    queue<pair<int, pair<int, int>>> q;
    q.push(mp(-1, mp(0, 0)));
    while(!q.empty()) {
        pair<int, pair<int, int>> front = q.front();
        q.pop();
        wall = front.second.first, height = front.second.second, level = front.first + 1;
        if(front.first >= height)    continue;
        if(height >= n)     return 1;
        if(isValid(wall, height + 1, Vis, left, right)) 
            q.push(mp(level ,mp(wall, height + 1)));
        if(isValid(wall, height - 1, Vis, left, right))
            q.push(mp(level, mp(wall, height - 1)));
        if(isValid(!(wall), height + k, Vis, left, right))
            q.push(mp(level , mp(!(wall), height + k)));
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string left, right;
    cin >> left >> right;
    bool result = bfs(left, right, k, n);
    if(result)  cout << "YES";
    else    cout << "NO";    
    return 0;
}


