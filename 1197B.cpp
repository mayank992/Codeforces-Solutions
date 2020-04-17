#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[200000], max = 0;
    int idx = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }
    bool bit = 1;
    for(int i = idx - 1; i >= 0; i--) {
        if(arr[i] > arr[i+1]) {
            bit = 0;
            break;
        }
    }
    if(bit == 1) {
        for(int i = idx + 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                bit = 0;
                break;
            }
        }
    }
    if(bit == 0)
        cout << "NO\n";
    else 
        cout << "YES\n";
    return 0;
}


