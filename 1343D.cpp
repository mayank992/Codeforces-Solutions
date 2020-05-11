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

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.ff < b.ff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, brr[100000]; pair<int, int> arr[100000];
        cin >> n;
        for(int i = 0; i < n; i++) {
            if(i < n/2)
                cin >> arr[i].ff;
            else {
                int index = i - (n/2);
                cin >> arr[index].ss;
                if(arr[index].ss > arr[index].ff)
                    swap(arr[index].ff, arr[index].ss);
            }
        }
        sort(arr, arr + n/2, cmp);
        for(int i = 0; i < n / 2; i++)
            brr[i] = arr[i].ff + arr[i].ss;
        for(int i = 0; i < n/2; i++)
            cout << arr[i].ff << " " << arr[i].ss << " " << brr[i] << "\n";
    }    
    return 0;
}

// 7 1 1 7 6 3 4 6
// 6 4 3 7 6 3 4 6
// 1 4 3 1 6 3 4 6



