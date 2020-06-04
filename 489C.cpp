/*
Platform: Codeforces
Problem: Given Length and Sum of Digits...
Problem Link: https://codeforces.com/problemset/problem/489/C
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
int n, s;
int minResult[100], maxResult[100];
bool memo[100][901];
bool solveMin(int i, int n, int s) {
    if (s < 0) return 0;
    if (i == n) { 
        if (s == 0) return 1;
        else    return 0;
    }
    if (memo[i][s] == 0)   
        return 0;
    for (int dig = ((i == 0)? 1: 0); dig <= 9; dig++) {
        if (solveMin(i + 1, n, s - dig)) {
            minResult[i] = dig;
            return 1;
        }
    }
    return memo[i][s] = 0;
}

int solveMax(int i, int n, int s) {
    if (s < 0) return 0;
    if (i == n) { 
        if (s == 0) return 1;
        else    return 0;
    }
    if(memo[i][s] == 0)
        return 0;
    for (int dig = 9; dig >= 0; dig--) {
        if (solveMax(i + 1, n, s - dig)) {
            maxResult[i] = dig;
            return 1;
        }
    }
    return memo[i][s] = 0;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    if(n == 1 && s == 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    mem(memo, 1);  bool exist = solveMin(0, n, s);    
    mem(memo, 1);  solveMax(0, n, s);
    if (!exist)
        cout << -1 << " " << -1 << "\n";
    else {
        for (int i = 0; i < n; i++)
            cout << minResult[i];
        cout << " ";
        for (int i = 0; i < n; i++) 
            cout << maxResult[i];
        cout << "\n";
    }
    return 0;
}


