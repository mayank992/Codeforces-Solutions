/*
Platform: Codeforces
Problem: Count Triangles
Problem Link: https://codeforces.com/problemset/problem/1355/C
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

// Solution 1
// ll getSum(ll n) {
//     return (n * (n+1)) / 2;
// }

// int main() { 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int A, B, C, D;
//     ll result = 0;
//     cin >> A >> B >> C >> D;    int y = B;
//     for(int z = C; z <= D; z++) {
//         int min_x = INT_MAX;
//         while(y <= C && min_x > B) {
//             min_x = z - y + 1;
//             if(min_x > B)   y++;
//         }
//         min_x = max(A, min_x);
//         if(y > C)   break;
//         min_x = B - min_x + 1;
//         int possible_ys = C - y + 1;
//         int _min = min(B - A + 1, possible_ys + min_x - 1);
//         result += getSum(_min) - getSum(min_x - 1);
//         if(possible_ys + min_x - 1 > B-A+1) {
//             result += (1LL * (B-A+1)) * (possible_ys + min_x - 1 - _min);
//         }
//     }
//     cout << result;
//     return 0;
// }

//Solution2
ll cnt[2000000] = {0}; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for(int x = A; x <= B; x++) {
        cnt[x + B]++;
        cnt[x + C + 1]--;
    }
    int n = 2000000;
    for(int i = 1; i < n; i++) {
        cnt[i] += cnt[i-1];
    }
    ll result = 0;
    for(int i = 1; i < n; i++) {
        if(i > C)
            result += cnt[i] * (min(i-1, D) - C + 1);
    }
    cout << result;
    return 0;
}
