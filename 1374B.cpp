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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        set<int> s;
        int n, temp, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            s.insert(temp);
        }
        if(s.size() > k)
            cout << -1 << "\n";
        else {
            cout << n * k << "\n";
            for(int i = 0; i < n; i++) {
                for(int j: s)
                    cout << j << " ";
                for(int j = 0; j < k - s.size(); j++)
                    cout << 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// int main() {
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout); 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, k, temp, count[101] = {0}, c = 0;
//         int arr[100];
//         cin >> n >> k;
//         for(int i = 0; i < n; i++) {
//             cin >> arr[i];
//             if(count[arr[i]] == 0)    c++;
//             count[arr[i]]++;
//         }
//         if(c == 1) {
//             cout << n << "\n";
//             for(int i = 0; i < n; i++)
//                 cout << arr[i] << " ";
//             cout << "\n";
//         }
//         else if(c > k)
//             cout << "-1" << "\n";
//         else {
//             vector<int> vec;
//             for(int i = 1; i <= 100; i++) {
//                 if(count[i] > 0)
//                     vec.pb(i);
//             }
//             for(int i = 0; i < k-c; i++)
//                 vec.pb(1);
//             cout << n * vec.size() << "\n";
//             for(int i = 0; i < n; i++) 
//                 for(int j = 0; j < vec.size(); j++)
//                     cout << vec[j] << " "; 
//             cout << "\n";
//         }
//     }       
//     return 0;
// }


