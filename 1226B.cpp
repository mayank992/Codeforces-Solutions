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
        ll x;
        cin >> x;
        ll temp = x % 14;
        if(x > 14 && temp >= 1 && temp <= 6)
            cout << "YES\n";
        else 
            cout << "NO\n"; 
    }    
    return 0;
}


