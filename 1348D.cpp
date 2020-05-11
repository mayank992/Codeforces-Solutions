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
        int n, temp = 0, add = 1;
        cin >> n;   
        vector<int> vec; 
        for(int i = 1; i <= n; i *= 2) {
            vec.pb(i);
            n -= i;
        }
        if(n > 0) {
            vec.pb(n);
            sort(all(vec));
        }
        cout << vec.size() - 1 << "\n";
        for(int i = 0; i < vec.size() - 1; i++)
            cout << vec[i+1] - vec[i] << " ";
        cout << "\n";
    }    
    return 0;
}


