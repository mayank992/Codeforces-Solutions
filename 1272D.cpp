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
    int n;  cin >> n;    
    int arr[n + 2], pre[n + 2], suf[n + 2];
    arr[0] = 0; arr[n + 1] = INT_MAX;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    pre[0] = suf[n + 1] = 0;
    pre[1] = suf[n] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] < arr[i])
            pre[i] = pre[i - 1] + 1;
        else    
            pre[i] = 1;
        if (arr[n - i + 1] < arr[n - i + 2])
            suf[n - i + 1] = suf[n - i + 2] + 1;
        else 
            suf[n - i + 1] = 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = max(result, max(pre[i], suf[i]));
        if (arr[i - 1] < arr[i + 1])
            result = max(result, pre[i - 1] + suf[i + 1]);
    }
    cout << result << "\n";
    return 0;
}

