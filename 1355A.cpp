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

pair<int, int> getMM(ll n) {
    pair<int, int> d = {10, 0};
    while(n > 0) {
        int dig = n % 10;
        if(dig < d.ff)
            d.ff = dig;
        if(dig > d.ss)
            d.ss = dig;
        n /= 10;
    }
    return d;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll a = 1, b = 1, i = 1;
        while(a != 0 && b != 0 && i < k) {
            pair<int, int> d = getMM(n);
            a = d.ff, b = d.ss;
            n += (a * b);
            i++;
        }
        cout << n << "\n";
    }
    return 0;
}


