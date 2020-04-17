#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, max_length = 0, count_A = 0, count_B = 0, first = 0, second = 0, k;
    string str;
    cin >> n >> k;
    cin >> str;
    while(second < str.length()) {
        if(str[second] == 'a')
            count_A++;
        else 
            count_B++;
        if(min(count_A, count_B) <= k)
            max_length++;
        else {
            if(str[first] == 'a')
                count_A--;
            else 
                count_B--;
            first++;
        }
        second++;
    }
    cout << max_length << "\n";
    return 0;
}
