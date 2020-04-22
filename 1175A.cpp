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
        ll k, n, result = 0; 
        cin >> n >> k;
        if(k == 1) {
            cout << n << "\n";
            continue;
        }
        while(n != 0) {
            if(n % k == 0) { 
                n = n / k;
                result++;
            }
            else {
                ll temp = n % k;
                n -= temp;
                result += temp;
            } 
        }
        cout << result << "\n";
    }
    return 0;
}


