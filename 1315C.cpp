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
#define pii	     pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        umap<int, bool> mappy;
        int n;  cin >> n;   int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mappy[arr[i]] = 1;
        }
        vector<int> result;
        bool exist = 1;
        for (int i = 0; i < n; i++) {
            int j;
            for (j = arr[i] + 1; j <= 2 * n; j++) {
                if (mappy[j] == 0) {
                    result.pb(arr[i]);
                    result.pb(j);
                    mappy[j] = 1;
                    break;
                }
            }
            if (j == (2 * n) + 1) {
                exist = 0; break;
            }
        }
        if (exist) {
            for (int i: result)
                cout << i << " ";
        }
        else 
            cout << -1;
        cout << "\n";
    }    
    return 0;
}


