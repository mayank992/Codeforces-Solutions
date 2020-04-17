#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        float temp = (float)(y - x) / (a + b);
        int c = ceil(temp);
        if(c == temp)
            cout << (int )temp << "\n";
        else 
            cout << -1 << "\n";
    }
    return 0;
}