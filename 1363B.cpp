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
        string str; cin >> str;
        int n = str.length(), one[1002] = {0}, zero[1002] = {0};
        for (int i = 1; i <= n; i++) {
            zero[i] = zero[i - 1];
            one[i] = one[i - 1];
            if (str[i - 1] == '0')
                zero[i]++;
            else 
                one[i]++;
        }
        int result = INT_MAX;
        // i is the breaking point
        for (int i = 1; i <= n; i++) {
            int res1 = one[i - 1] + (zero[n] - zero[i]);
            int res2 = zero[i - 1] + (one[n] - one[i]);
            result = min(result, min(res1, res2));
        }   
        cout << result << "\n";
    }
    return 0;
}


