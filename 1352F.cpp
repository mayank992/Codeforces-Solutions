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
        int n0, n1, n2;
        vector<bool> result;
        cin >> n0 >> n1 >> n2;
        if(n2 > 0) {
            for(int i = 0; i <= n2; i++)
                result.pb(1);
        }
        if(n1 > 0) {
            if(n2 > 0) {
                bool start = 0;
                for(int i = 0; i < n1; i++) {
                    result.pb(start);
                    start = !start;
                }
            }
            else {
                bool start = 1;
                for(int i = 0; i <= n1; i++) {
                    result.pb(start);
                    start = !start;
                }
            }
        }
        if(n0 > 0) {
            if(result.empty()) {
                for(int i = 0; i <= n0; i++)
                    result.pb(0);
            }
            else if(result.back() == 0) {
                for(int i = 0; i < n0; i++)
                    result.pb(0);
            }
            else {
                int N = result.size();
                if(result[N-1] == 1 && result[N-2] == 1) {
                    result.vpop();
                    for(int i = 0; i <= n0; i++)
                        result.pb(0);
                    result.pb(1);
                }
                else {
                    result.vpop();
                    for(int i = 0; i < n0; i++)
                        result.pb(0);
                    result.pb(1);
                }
            }
        }
        for(bool i: result)
            cout << i;
        cout << "\n";
    }    
    return 0;
}


