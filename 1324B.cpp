#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        int arr[5000];
        unordered_map<int, int> count;
        bool bit = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i != 0)
                count[arr[i]]++;
        }
        for(int idx = 1; idx <= n-2; idx++) {
            count[arr[idx]]--;
            for(int j = idx-1; j >= 0; j--) {
                if(count[arr[j]] > 0) {
                    bit = 1;
                    break;
                }
            }
            if(bit == 1)
                break;
        }
        if(bit == 0)
            cout << "NO\n";
        else 
            cout << "YES\n";
    }    
    return 0;
}
