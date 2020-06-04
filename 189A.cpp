/*
Platform: Codeforces
Problem: Cut Ribbon
Problem Link: https://codeforces.com/problemset/problem/189/A
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
int a, b, c;

// int memo[4001];
// int solve(int n) {
//     if (n < 0)   return INT_MIN;
//     if (n == 0)
//         return 0;
//     if (memo[n] != -1)  return memo[n];
//     return memo[n] = max(solve(n - a), max(solve(n - b), solve(n - c))) + 1;
// }

// int main() { 
//     mem(memo, -1);
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n >> a >> b >> c;
//     cout << solve(n);
//     return 0;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c, result = 0;
    cin >> n >> a >> b >> c;
    // xa + yb + zc = n
    for (int x = 0; x <= (n / a) + 1; x++) {
        for (int y = 0; y <= (n / b) + 1; y++) {
            int temp = (n - (x * a) - (y * b));
            if (temp >= 0 && temp % c == 0) {
                int z = temp / c;
                result = max(result, x + y + z);
            }
        }
    }
    cout << result;
    return 0;
}
