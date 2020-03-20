#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, arr[100];
    cin >> t;
    while(t--) {
        int max = 0, i, n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] > max)
                max = arr[i];
        }
        for(i = 0; i < n; i++) {
            if((arr[i] - max) & 1)
                break;
        }
        if(i == n)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }    
    return 0;
}
