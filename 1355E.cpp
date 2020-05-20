/*
Platform: Codeforces
Problem: Restorer Distance
Problem Link: https://codeforces.com/problemset/problem/1355/E
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
#define pii      pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;
int n, A, R, M, height[100000];

ll findCost(int mid) {
    ll need = 0, extra = 0;
    for(int i = 0; i < n; i++) {
        if(height[i] < mid)
            need += mid - height[i];
        else if(height[i] > mid) {
            extra += height[i] - mid;
        }
    }
    ll costCase1, costCase2;
    if(extra >= need)
        costCase1 = (need * M) + ((extra - need) *  R);
    else
        costCase1 = (extra * M) + ((need - extra) * A);
    costCase2 = (extra * R) + (need * A);
    return min(costCase1, costCase2);
}

ll ts(int _min, int _max) {
    int l = _min, h = _max;
    ll result = LLONG_MAX;
    while(l <= h) {
        int var = (h - l) / 3;
        int mid1 = l + var, mid2 = h - var;
        if(h - l <= 2) {
            for(int a = l; a <= h; a++) {
                result = min(result, findCost(a));
            }
            return result;
        }
        ll cost1 = findCost(mid1), cost2 = findCost(mid2);
        if(cost1 > cost2) {
            result = min(result, cost2);
            l = mid1;
        }
        else {
            result = min(result, cost1);
            h = mid2;
        }
    }
    return result;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _min = INT_MAX, _max = 0;
    cin >> n >> A >> R >> M;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
        _min = min(_min, height[i]);
        _max = max(_max, height[i]);
    }
    cout << 1LL * ts(_min, _max);
    return 0;
}


