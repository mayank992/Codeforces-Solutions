// Make Them Odd
#include<bits/stdc++.h>

using namespace std;

int main() {
    map<int, bool> mappy;
    int t, n, temp, result;
    cin >> t;
    while(t--) {
        result = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            while(temp % 2 == 0 && mappy[temp] == 0) {
                mappy[temp] = 1;
                temp = temp >> 1;
                result++;
            }
        }
        cout << result << "\n";
        mappy.clear();
    }    
    return 0;
}
