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

bool cmp(const pii &a, const pii &b) {
    if (a.ss == b.ss)
        return a.ff > b.ff;
    return a.ss < b.ss;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  pii arr[9];
    cin >> n;
    bool exist = 0;    
    for (int i = 0; i < 9; i++) {
        int temp;   cin >> temp;
        arr[i] = {i + 1, temp};
        if (temp <= n)  exist = 1;
    }
    if (!exist) 
        cout << -1;
    else {
        sort(arr, arr + 9, cmp);
        while (n > 0) {
            int digit = 0, maxDigits = 0, choosen = 0;  bool exist1 = 0;
            for (int i = 0; i < 9; i++) {
                int temp = (n - arr[i].ss) / arr[0].ss;
                if (temp >= maxDigits && arr[i].ss <= n && arr[i].ff > digit) {
                    exist1 = 1;
                    choosen = arr[i].ss;
                    maxDigits = temp;
                    digit = arr[i].ff;
                }
            }
            if (!exist1)    break;
            cout << digit;  
            n -= choosen;
        }
    }
    return 0;
}

