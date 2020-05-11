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
    string str;
    cin >> str;
    int i = 0, j = str.length()-1;
    while((str[i] != '1' || str[j] != '1') && i < str.length()) {
        if(str[i] == '0')   i++;
        if(str[j] == '0')   j--;
    }    
    if(i == str.length())
        cout << '0';
    else {
        int temp = str.length() - i;
        if(i == j && temp & 1) 
            cout << ceil((float)temp / 2) - 1;
        else 
            cout << ceil((float)temp / 2);
    }
    return 0;
}


