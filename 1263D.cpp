#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()
// Disjoint Set Union Data Structure
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
    int parent[26];
    memset(parent, -1, sizeof(parent));
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for(int i = 0; i < str.length(); i++) {
            if(i == 0 && parent[str[i] - 'a'] == -1)
                parent[str[i] - 'a'] = str[i] - 'a';
            if(i > 0)
                _union(parent, str[i-1] - 'a', str[i] - 'a');
        }
    }
    set<int> result;
    for(int i = 0; i < 26; i++) {
        if(parent[i] != -1)
            result.insert(_find(parent, i));
    }
    cout << result.size();
    return 0;
}
