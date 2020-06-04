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

// O(nlogn) => BEST
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ele;  double x;
    cin >> n >> m;
    vector<int> arr(n), vec;
    for(int i = 0; i < n; i++) 
        cin >> arr[i] >> x;
    vec.pb(arr[0]);
    for(int i = 1; i < n; i++) {
        auto idx = upper_bound(all(vec), arr[i]);
        if(idx == vec.end())
            vec.pb(arr[i]);
        else 
            *idx = arr[i];
    }
    cout <<  n - vec.size();
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m, ele;  double x;
//     cin >> n >> m;
//     vector<int> arr(n), vec(n+1, INT_MAX);
//     for(int i = 0; i < n; i++) 
//         cin >> arr[i] >> x;
//     vec[0] = INT_MIN;
//     for(int i = 0; i < n; i++) {
//         auto idx = upper_bound(all(vec), arr[i]) - vec.begin();
//         if(vec[idx - 1] <= arr[i] && arr[i] < vec[idx])
//             vec[idx] = arr[i];
//     }
//     int result = 1;
//     for(int i = 0; i <= n; i++) {
//         if(vec[i] < INT_MAX)
//             result = i;
//     }
//     cout << n - result;
//     return 0;
// }


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


