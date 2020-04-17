// EVEN BUT NOT EVEN

#include<bits/stdc++.h>

using namespace std;

void remove_even(string &str, int &n) {
    int last_digit = (int )(str[n-1] - '0');
    while(last_digit % 2 == 0 && n != 0) {
        n = n - 1;
        str.pop_back();
        last_digit = (int )(str[n-1] - '0');
    }
}

void print_str(string &str) {
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if(str[i] != '0')
            break;
    }
    for(; i < str.length(); i++) {
        cout << str[i];
    }
    cout << "\n";
}

int main() {
    int t, n;
    string str;
    cin >> t;
    while(t-- ) {
        int sum = 0, odd = 0;
        cin >> n;
        cin >> str;
        if(n == 1 && ((int )(str[0] - '0')) % 2 == 0) {
            cout << "-1\n";
            continue;
        }
        remove_even(str, n);
        for(int it = n-1; it >= 0; it--) {
            int temp = (int )(str[it] - '0');
            if(temp % 2 != 0) odd++;
            sum += temp;
        }
        if(n != 0 && sum % 2 != 0) {
            int i;
            if(odd) {
                for (i = 0; i < n-1; i++)
                {
                    int temp = (int )(str[i] - '0');
                    if(temp % 2 != 0) {
                        str.erase(str.begin() + i);
                        break;
                    }
                }
                if(i == n-1) {
                    cout << "-1\n";
                    continue;
                }
            }
            else {
                cout << "-1\n";
                continue;
            }
        }
        if(n == 0)
            cout << "-1\n";
        else {
            print_str(str);
        }
    }    
    return 0;
}
