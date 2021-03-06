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
    int t, added[1001];
    cin >> t;
    while(t--) {
        memset(added, 0, sizeof(added));
        int n;
        cin >> n;
        if(n <= 3)  
            cout << "-1";
        else if(n == 4) {
            cout << "2 4 1 3";
        }
        else {
            for(int i = 1; i <= n; i += 2)
                cout << i << " ", added[i] = 1;
            int left = ((n & 1)? (n - 3): ((n-1) - 3));
            added[left] = 1;
            cout << left << " ";
            for(int i = n; i >= 2; i--)
                if(!added[i])   cout << i << " ";
        }
        cout << "\n";
    }    
    return 0;
}


