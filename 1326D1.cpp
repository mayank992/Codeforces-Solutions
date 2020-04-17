#include<bits/stdc++.h>

using namespace std;

bool is_palindrome(string str) {
    string temp = str;
    reverse(str.begin(), str.end());
    return (str == temp);
}

int main() {
    int t;
    string str;
    cin >> t;
    while(t--) {
        cin >> str;
        string out1, out2;
        bool bit = 1;
        int i = 0, j = str.length()-1;
        while(i <= j) {
            if(i == j) {
                out1.push_back(str[i++]);
            }
            else if(bit == 1 && str[i] == str[j]) {
                out1.push_back(str[i++]);
                out2.push_back(str[j--]);
            }
            else {
                while(str[i] != str[j] && i < j) {
                    j--;
                }
                if(i == j) {
                    out1.push_back(str[i++]);
                }
                else {
                    if(is_palindrome(str.substr(i, j-i+1))) {
                        out1 = out1 + str.substr(i, j-i+1);
                        break;
                    }
                    else 
                        j--;
                }
                bit = 0;
            }
        }
        reverse(out2.begin(), out2.end());
        out1 = out1 + out2;
        //-------------------------------------------------------
        bit = 1;
        i = 0, j = str.length()-1;
        out2.clear();
        string out3;
        while(i <= j) {
            if(i == j) {
                out2.push_back(str[i++]);
            }
            else if(bit == 1 && str[i] == str[j]) {
                out2.push_back(str[i++]);
                out3.push_back(str[j--]);
            }
            else {
                while(str[i] != str[j] && i < j) {
                    i++;
                }
                if(i == j) {
                    out2.push_back(str[i++]);
                }
                else {
                    if(is_palindrome(str.substr(i, j-i+1))) {
                        out2 = out2 + str.substr(i, j-i+1);
                        break;
                    }
                    else 
                        i++;
                }
                bit = 0;
            }
        }
        reverse(out3.begin(), out3.end());
        out2 = out2 + out3;
        // ------------------------------------------------------
        if(out1.length() >= out2.length())
            cout << out1 << "\n";
        else 
            cout << out2 << "\n";
    }
    return 0;
}
