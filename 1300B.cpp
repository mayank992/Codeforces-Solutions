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
        int n, arr[200000];
        cin >> n;
        for(int i = 0; i < 2*n; i++)
            cin >> arr[i];
        sort(arr, arr+(2*n));
        cout << arr[n] - arr[n-1] << "\n";
    }
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, arr[10];
//         cin >> n;
//         for(int i = 0; i < 2*n; i++)
//             cin >> arr[i];
//         sort(arr, arr+(2*n));
//         for(int i = 0; i < 2*n; i++)
//             cout << arr[i] << " ";
//         cout << "\n";
//         ll a = 0, b = 0;
//         for(int i = 0; i < (2*n); i += 2) {
//             a += arr[i];
//             b += arr[i+1];
//         }
//         int i = 2;
//         while(a < b && i < (2*n)) {
//             a += arr[i-1];
//             b -= arr[i-1];
//             i += 2;
//         }
//         i = (i-2)/2;
//         if((n+i) & 1 && (n-i) & 1)
//             cout << abs(a - b) << "\n";
//         else 
//             cout << abs((a - arr[0]) - (b + arr[0])) << "\n";
//     }
//     return 0;
// }

