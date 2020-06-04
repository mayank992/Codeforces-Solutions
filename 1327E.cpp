#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define MOD 998244353
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

ll mfast_pow(ll base, ll power, ll mod) {
    ll result = 1;
    while(power > 0) {
        if(power & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int len = 1; len <= n; len ++) {
        if (len == n)
            cout << 10;
        else if (len == n - 1)
            cout << 180 << " ";
        else {
            int pos = n - len + 1, count = n - len;
            ll case1 = ((ll )mfast_pow(10, count - 1, MOD) * 9) % MOD;
            ll case2 = ((ll )mfast_pow(10, count - 2, MOD) * 81) % MOD;
            case1 = (case1 * 2) % MOD;
            case2 = (case2 * (pos - 2)) % MOD;
            ll ans = (case1 + case2) % MOD;
            ans = (ans * 10) % MOD;
            cout << ans << " ";
        }
    }
    return 0;
}


