/*
Platform: Codeforces
Problem: Moving Points
Problem Link: https://codeforces.com/problemset/problem/1311/F
*/

#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define mem(a,v) memset(a, v, sizeof(a))
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
#define umap	 unordered_map
#define pii		 pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

struct d {ll value = 0; int count = 0;};
class BinaryIndexedTree {
    private:
        int Size;
        umap<int, d> Table;
    public:
        BinaryIndexedTree(int size): Size(size+1) {}
        pair<ll, int> getDist(int index) {
            ll sum = 0; int count = 0;
            while(index > 0) {
                sum += Table[index].value;
                count += Table[index].count;
                index -= (index & (-index));
            }
            return mp(sum, count);
        }
        void updateDist(int index, ll value) {
            while(index < Size) {
                Table[index].value += value;
                Table[index].count += 1;
                index += (index & (-index));
            }
        }
        pair<ll, int> rangeDist(int index1) {
            pair<ll, int> a, b;
            a = getDist(index1 - 1);
            b = getDist(Size - 1);
            return mp((b.ff - a.ff), (b.ss - a.ss));
        }
        void clear() {
            Table.clear();
        }
};

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  ll p, v;
    cin >> n;
    pair<ll, ll> points[n];
    for(int i = 0; i < n; i++) {
        cin >> p;   points[i].ff = p;
    }
    for(int i = 0; i < n; i++) {
        cin >> v;   points[i].ss = v;
    }
    sort(points, points + n);
    int posCount = 0, negCount = 0;
    ll negDist = 0, result = 0;  BinaryIndexedTree B(1e8 + 2);
    for(int i = 0; i < n; i++) {
        ll curDist = 0;
        if(points[i].ss >= 0) {
            pair<ll, int> cur = B.getDist(points[i].ss);
            curDist = (cur.ss * points[i].ff) - cur.ff;
            curDist += (negCount * points[i].ff);
            curDist -= negDist;
        }
        if(points[i].ss <= 0)
            negCount++, negDist += points[i].ff;
        else
            B.updateDist(points[i].ss, points[i].ff);
        result += curDist;
    }
    B.clear();
    for(int i = 0; i < n; i++) {
        ll curDist = 0;
        if(points[i].ss < 0) {
            pair<ll, int> cur = B.rangeDist(abs(points[i].ss));
            curDist = (cur.ss * points[i].ff) - cur.ff;
        }
        if(points[i].ss < 0)
            B.updateDist(abs(points[i].ss), points[i].ff);
        result += curDist;
    }
    cout << result << "\n"; 
    return 0;
}


