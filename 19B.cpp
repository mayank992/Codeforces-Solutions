/*
Platform: Codeforces
Problem: Checkout Assistant
Problem Link: https://codeforces.com/contest/19/problem/B
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
const int MOD  =  1e9 + 7, DPConst = 2001;
const ll INF   =  1e13;

ll memo[2001][5010];
ll getMin(int t[], int c[], int n, int timeLeft) {
    if (n == 0) {
        if (timeLeft >= 0)   return 0;
        else    return INF;
    }
    if (memo[n][timeLeft + DPConst] != -1)
        return memo[n][timeLeft + DPConst];
    ll result1 = INF, result2 = INF;
    result1 = getMin(t, c, n - 1, timeLeft - 1);
    result2 = c[n - 1] + getMin(t, c, n - 1, timeLeft + t[n - 1]);
    return memo[n][timeLeft + DPConst] = min(result1, result2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n;  cin >> n; 
    int t[n], c[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }
    cout << getMin(t, c, n, 0);
    return 0;
}


