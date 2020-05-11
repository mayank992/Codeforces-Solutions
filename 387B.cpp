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
    int n, m, arr[3000], brr[3000];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> brr[i];
    }
    int i = 0, j = 0, result = 0;
    while(i < n && j < m) {
        if(arr[i] == brr[j])
            i++;
        else if(arr[i] < brr[j])
            i++, j++;
        else 
            j++; 
    }
    result += (n - i);
    cout << result;
    return 0;
}


