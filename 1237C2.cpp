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
const int MAX = 50000;
class points {
    public:
        int axis[3];
        int n;
    points(int a = -1, int b = -1, int c = -1, int d = -1) {
        axis[0] = a, axis[1] = b, axis[2] = c, n = d;
    }
};

points point[MAX];
vector<pair<int, int>> result;
int N; 

bool cmpx(points &a, points &b){return a.axis[0] < b.axis[0];}
bool cmpy(points &a, points &b){return a.axis[1] < b.axis[1];}
bool cmpz(points &a, points &b){return a.axis[2] < b.axis[2];}

points solve(int i, int j, int axis) {
    vector<points> current;
    vector<pair<int, int>> subproblems;
    if(i == j)
        return point[i];
    else if(i+1 == j) {
        result.pb(mp(point[i].n, point[j].n));
        return points(-1, -1, -1, -1);
    }
    sort(point+i, point+j+1, ((axis == 0)? cmpx: ((axis == 1)? cmpy: cmpz)));
    int k = i, l = i+1;
    while(l <= j) {
        if(point[k].axis[axis] == point[l].axis[axis])
            l++;
        else {
            subproblems.pb(mp(k, l-1));
            k = l;
        }
    }subproblems.pb(mp(k, l-1));
    for(int k = 0; k < (int )subproblems.size(); k++) {
        points temp = solve(subproblems[k].ff, subproblems[k].ss, axis+1);
        if(temp.n != -1)
            current.pb(temp);
    }
    for(int k = 0; k < (int )current.size()-1; k += 2) {
        result.pb(mp(current[k].n, current[k+1].n));
    }
    if((int )current.size() & 1)    return current[current.size()-1];
    else    return points(-1, -1, -1, -1);
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> point[i].axis[0] >> point[i].axis[1] >> point[i].axis[2];
        point[i].n = i+1;
    }
    solve(0, N-1, 0);
    for(int i = 0; i < result.size(); i++)
        cout << result[i].ff << " " << result[i].ss << "\n";
    return 0;
}


