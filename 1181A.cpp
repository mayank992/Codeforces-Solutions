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
    ll n, m, c;
    cin >> n >> m >> c;
    if(n % c == 0 || m % c == 0) {
        cout << (n/c) + (m/c) << " " << "0";
    }
    else {
        ll result = (n/c) + (m/c);
        n -= (n/c) * c;
        m -= (m/c) * c;
        if(n + m >= c) {
            cout << result + 1 << " ";
            if(n < m)
                cout << c - m;
            else 
                cout << c - n;
        }
        else 
            cout << result << " " << "0";
    }
    return 0;
}


