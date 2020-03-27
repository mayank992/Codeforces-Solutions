// Perfect Keyboard
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
        string str;
        bool mappy[26] = {0};
        char result[52] = {0};
        bool left_right = 0; // 0 for right // 1 for left
        cin >> str;
        int i, j = 24;
        for(i = 0; i < str.length(); i++) {
            if(str[i] == result[j-1]) {
                j--;
                left_right = 1;
            }
            else if(str[i] == result[j+1]) {
                j++;
                left_right = 0;
            }
            else {
                if(result[j+1] == '\0' && mappy[str[i] - 'a'] == 0) {
                    left_right = 0;
                    mappy[str[i] - 'a'] = 1;
                    result[++j] = str[i];
                }
                else if(result[j-1] == '\0' && mappy[str[i] - 'a'] == 0) {
                    left_right = 1;
                    mappy[str[i] - 'a'] = 1;
                    result[--j] = str[i];
                }
                else {
                    cout << "NO\n";
                    goto end;
                }
            }
        }
        if(i == (int )str.length()) {
            // output
            cout << "YES\n";
            bool bit = 1;
            for(int i = 0; i < 52; i++) {
                if(bit == 1 || result[i] != '\0') {
                    if(result[i] != '\0') {
                        cout << (char )result[i];
                        bit = 0;
                    }
                }
                if(bit == 0 && result[i] == '\0')
                    break;
            }
            for(int i = 0; i < 26; i++) {
                if(mappy[i] == 0) 
                    cout << (char)('a' + i);
            }
            cout << "\n";
        }
        end: ;
    }
    return 0;
}


