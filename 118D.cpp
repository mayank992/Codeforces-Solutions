#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define mod1 100000000
#define pb push_back
#define poppop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()
int dp[101][101][11][11];

// Recursive Solution (Top-Down) Dynamic Programming Memoisation
int solve1(int n1, int n2, int k1, int k2, int F_count, int H_count) {
    if(n1 == 0 && n2 == 0)
        return 1;
    if(dp[n1][n2][k1-F_count][k2-H_count] == -1) {
        int count = 0;
        if(n1 > 0 && F_count < k1) {
            count += (solve1(n1-1, n2, k1, k2, F_count+1, 0) % mod1);
        }
        if(n2 > 0 && H_count < k2) {
            count += (solve1(n1, n2-1, k1, k2, 0, H_count+1) % mod1);
        }
        dp[n1][n2][k1-F_count][k2-H_count] = count % mod1;
    }
    return dp[n1][n2][k1-F_count][k2-H_count];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    clock_t a = clock();
    memset(dp, -1, sizeof(dp));
    clock_t b = clock();
    cout << fixed << setprecision(6) << (float )(b-a)/CLOCKS_PER_SEC << "\n";
    cout << solve1(n1, n2, k1, k2, 0, 0) << "\n";
    return 0;
}
