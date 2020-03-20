#include<bits/stdc++.h>

using namespace std;

bool is_possible(string str, int mid) {
    int start = 0;
    for(int i = 1; i <= str.length(); i++) {
        if(i - start > mid)
            return 0;
        if(str[i-1] == 'R')
            start = i;
    }
    if(start >= str.length() - mid + 1) {
        return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int result = INT_MAX, i;
        string str;
        cin >> str;
        for(i = 0; i < str.length(); i++) {
            if(str[i] == 'R')
                break;
        }
        if(i == str.length()) {
            cout << str.length() + 1 << "\n";
            continue;
        }
        int min = 1, max = str.length();
        while(min <= max) {
            int count[str.length()] = {0};
            int mid = min + (max - min) / 2;
            if(is_possible(str, mid)) {
                result = std::min(result, mid);
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }
        cout << result << "\n";
    }    
    return 0;
}
