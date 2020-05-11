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

int search(int dp[], int l, int h, int key) {
    while(l <= h) {
        int mid = (l + h) / 2;
        if(dp[mid] == key)
            return mid;
        else if(key < dp[mid])
            h = mid - 1;
        else 
            l = mid + 1;
    }
    return l;
}

//O(nlogn)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num, len = -1, dp[5000] = {0};
    double x;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num >> x;
        int idx = search(dp, 0, len, num);
        if(idx > len)
            len++;
        dp[idx] = num;
    }
    cout << n - (len + 1);
    return 0;
}

// int main() {
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout); 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m, arr[5000], _max = 1;
//     double x;
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i] >> x;
//     }
//     int LIS[5000] = {1};
//     for(int i = 1; i < n; i++) {
//         LIS[i] = 1;
//         for(int j = i-1; j >= 0; j--) {
//             if(arr[j] <= arr[i])
//                 LIS[i] = max(LIS[i], LIS[j] + 1);
//         }
//         _max = max(LIS[i], _max);
//     }
//     cout << n - _max;
//     return 0;
//}


