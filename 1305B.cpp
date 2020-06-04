#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> vec;
    int n = str.length();
    int i = 0, j = n - 1;
    while (i < j) {
        if (str[i] == '(' && str[j] == ')') {
            vec.push_back(i + 1);
            vec.push_back(j + 1);
            // str[i] = str[j] = '.';
            i++, j--;
        }
        else if(str[i] == '(')
            j--;
        else    
            i++;
    }
    sort(vec.begin(), vec.end());
    if (vec.size()) {
        cout << 1 << "\n";
        cout << vec.size() << "\n";
        for (int i: vec)
            cout << i << " ";
    }
    else 
        cout << 0;
    // cout << "\n";
    // cout << str << "\n";
    return 0;
}