#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, start, end;
    string str;
    cin >> t;
    while(t--) {
        start = end = 0;
        int alphabet[26] = {0};
        vector<char> vec;
        cin >> str;
        while(end != str.length()) {
            while(str[start] == str[end] && str[end] == str[end+1])
                end++;
            if(alphabet[str[end] - 'a'] == 0 && (end-start+1) % 2 != 0) {
                vec.push_back(str[end]);
                alphabet[str[end] - 'a'] = 1;
            }
            end++;
            start = end;
        }
        sort(vec.begin(), vec.end());
        for(auto it = vec.begin(); it != vec.end(); it++) 
            cout << *it;
        cout << "\n";
    }    
    return 0;
}
