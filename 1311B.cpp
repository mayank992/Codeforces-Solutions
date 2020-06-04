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
        umap<int, bool> isAllowed;
        int n, m;
        cin >> n >> m;
        int arr[n], pos;
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        for (int i = 0; i < m; i++) {
            cin >> pos;
            isAllowed[pos - 1] = 1;
        }
        bool result = 1;
        for (int i = 0; result && i < n - 1; i++) {
            for (int j = 0; result && j < n - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    if (isAllowed[j])
                        swap(arr[j], arr[j + 1]);
                    else
                        result = 0;
                }
            }
        }
        if (result)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}


