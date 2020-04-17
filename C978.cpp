#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int n, m, start;
    ll dormitories[200000], temp1, temp2 = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> dormitories[i];
    for (int i = 0; i < m; i++) {
        cin >> temp1;
        while(temp2 < temp1) {
            temp2 += dormitories[start++];
        }
        if(temp1 == temp2)
            cout << start << " " << dormitories[start - 1] << "\n";
        else 
            cout << start << " " << temp1 - (temp2 - dormitories[start - 1]) << "\n";
    }
    return 0;
}
