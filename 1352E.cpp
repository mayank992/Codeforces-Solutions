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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, temp;
        pair<int, bool> arr[8000];
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i].ff;
        }
        for(int i = 0; i < n; i++) {
            int sum = arr[i].ff;
            for(int j = i+1; j < n; j++) {
                sum += arr[j].ff;
                if(sum <= 8000 && arr[sum-1].ss == 0)
                    arr[sum-1].ss = 1;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[arr[i].ff-1].ss)
                count++;
        }
        cout << count << "\n";
    }    
    return 0;
}


