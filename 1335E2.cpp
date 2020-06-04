/*
Platform: Codeforces
Problem: Three Blocks Palindrome (hard version)
Problem Link: https://codeforces.com/problemset/problem/1335/E2
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, result = 1;
        cin >> n;
        int arr[n], suffix[202][n];
        mem(suffix, 0);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if(n == 1) {
            cout << 1 << "\n";
            continue;
        }
        suffix[arr[n-1]][n-1]++;
        for(int i = 1; i <= 200; i++) {
            for(int j = n-2; j >= 0; j--) {
                if(arr[j] == i)
                    suffix[i][j]++;
                suffix[i][j] += suffix[i][j+1]; 
            }
        }
        for(int a = 1; a <= 200; a++) {
            int i = 0, j = n-1, count = 0, res = 0;
            while(i < j) {
                if(arr[i] == a && arr[j] == a) {
                    int middle = 0; count += 1;
                    for(int k = 1; k <= 200; k++)
                        middle = max(middle, suffix[k][i+1] - suffix[k][j]);
                    result = max(result, 2 * count + middle);
                    i++, j--;
                }
                else if(arr[i] == a)
                    j--;
                else if(arr[j] == a)
                    i++;
                else 
                    i++, j--;
            }
            result = max(result, res);
        }
        cout << result << "\n";
    }
    return 0; 
}

//int suffix[202][200002] = {0};

// int main() { 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--) {
//         mem(suffix, 0);
//         int n;
//         cin >> n;
//         int arr[n];
//         for(int i = 1; i <= n; i++)
//             cin >> arr[i];
//         suffix[arr[n]][n]++;
//         for(int i = 1; i <= 200; i++) {
//             for(int j = n-1; j > 0; j--) {
//                 if(arr[j] == i)
//                     suffix[i][j]++;
//                 suffix[i][j] += suffix[i][j+1]; 
//             }
//         }
//         int result = 0;
//         for(int i = 1; i <= n; i++) {
//             int prefix = suffix[arr[i]][1] - suffix[arr[i]][i+1];
//             auto it = upper_bound((suffix[arr[i]]+1), (suffix[arr[i]]+(n+1)), prefix, greater<int>());
//             int j = it - (suffix[arr[i]] + 1);
//             if(suffix[arr[i]][j] != prefix)  continue;
//             int _max = 0;
//             if(j <= i)  continue;
//             if(i+1 == j-1)  _max = 1;
//             else {
//                 for(int k = 1; k <= 200; k++)
//                     _max = max(_max, suffix[k][i+1] - suffix[k][j]);
//             }
//             result = max(result, 2 * prefix + _max);
//         }
//         for(int i = 1; i <= 200; i++)
//             result = max(result, suffix[i][1]);
//         cout << max(result, 1) << "\n";
//     }
//     return 0;
// }