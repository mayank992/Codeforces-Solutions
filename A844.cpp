// Diversity
#include<bits/stdc++.h>

using namespace std;

int main() {
    bool arr[26] = {0};
    int k, n, count = 0;
    string str;
    cin >> str;
    cin >> k;
    if(str.length() < k) {
        cout << "impossible";
        return 0;
    }
    for(int i = 0; i < str.length(); i++) {
        if(arr[(int )(str[i] - 'a')] == 0)
            count++;
        arr[(int )(str[i] - 'a')] = 1;
    }
    if(count >= k) 
        cout << 0;
    else {
        cout << k - count;
    }
    return 0;
}
