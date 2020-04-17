#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n, arr[100000];
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        ll result = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i-1] > arr[i]) {
                ll diff = arr[i-1] - arr[i];
                ll msb = (ll)log2(diff);
                result = max(result, msb+1);
                arr[i] = arr[i-1];
            }
        }
        cout << result << "\n";
    }     
    return 0;
}


