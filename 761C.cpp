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

void compute(int dist[][3], vector<string> &strings, int n, int m) {
    for(int i = 0; i < n; i++) {
        dist[i][0] = dist[i][1] = dist[i][2] = 200;
        for(int j = 0; j < m; j++) {
            if(strings[i][j] >= 'a' && strings[i][j] <= 'z')
                dist[i][0] = min(dist[i][0], min(j, m-j));
            else if(strings[i][j] >= '0' && strings[i][j] <= '9')
                dist[i][1] = min(dist[i][1], min(j, m-j));
            else 
                dist[i][2] = min(dist[i][2], min(j, m-j));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a = 0, b = 0, c = 0;
    cin >> n >> m;
    vector<string> strings;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strings.pb(str);
        if(str[0] >= 'a' && str[0] <= 'z')  a++;
        else if(str[0] >= '0' && str[0] <= '9') b++;
        else c++;
    }
    if(a > 0 && b > 0 && c > 0)
        cout << 0;
    else {
        int dist[50][3];
        int result = 200;
        compute(dist, strings, n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j != i)
                for(int k = 0; k < n; k++) {
                    if(k != i && k != j)
                        result = min(result, dist[i][0] + dist[j][1] + dist[k][2]);
                }
            }
        }
        cout << result;
    }
    return 0;
}


