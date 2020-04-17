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
        int n, arr[100000];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int i, j;
        if(n & 1)
            i = j = n/2;
        else {
            i = (n/2)-1;
            j = n/2;
        }
        if(i == j) {
            cout << arr[i] << " ";
            i--;
            j++;
        }
        while(i >= 0 && j <= n) {
            cout << arr[j++] << " " << arr[i--] << " ";
        }
        cout << "\n";
    }    
    return 0;
}


