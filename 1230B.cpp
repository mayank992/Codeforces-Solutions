#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    if(k > 0 && str.length() == 1) {
        cout << "0";
        return 0;
    }
    for(int i = 0; i < n && k > 0; i++) {
        if(i == 0 && str[i] != '1') {
            str[0] = '1';
            k--;
        }
        else if(i != 0 && str[i] != '0') {
            str[i] = '0';
            k--;
        }
    }
    cout << str;    
    return 0;
}


