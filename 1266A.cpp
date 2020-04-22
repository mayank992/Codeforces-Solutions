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
    int n;
    cin >> n;
    while(n--) {
        int sum = 0, count1 = 0, count2 = 0;
        string str;
        cin >> str;
        for(int i = 0; i < str.length(); i++) {
            int digit = str[i] - '0';
            if(digit % 2 == 0 && digit > 0)  count1++;
            else if(digit == 0) count2++;
            sum += digit;
        }
        if(sum % 3 == 0 && (count2 >= 2 || (count1 > 0 && count2 > 0)))
            cout << "red\n";
        else 
            cout << "cyan\n";
    }
    return 0;
}


