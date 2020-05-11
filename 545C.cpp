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
    int n, x[100000], h[100000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }   
    if(n == 1) {
        cout << 1;
        return 0;
    }
    int result = 2, occ = x[0]; 
    for(int i = 1; i < n-1; i++) {
        if(x[i] - h[i] > occ) {
            occ = x[i];
            result++;
        }
        else if(x[i] + h[i] < x[i+1]) {
            occ = x[i] + h[i];
            result++;
        }
        else 
            occ = x[i];
    }
    cout << result;
    return 0;
}


