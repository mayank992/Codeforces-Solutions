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
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if((n / 2) & 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i <= n/2; i++)
            cout << i * 2 << " ";
        for(int i = 1; i <= n/2; i++) {
            if(i <= n/4)
                cout << (i * 2) - 1 << " ";
            else 
                cout << (i * 2) + 1 << " ";
        }
        cout << "\n";
    }    
    return 0;
}


