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
    int t, h, n, m;
    cin >> t;
    while(t--) {   
        cin >> h >> n >> m;
        while(h > 20 && n > 0) {
            h = (h / 2) + 10;
            n--;
        } 
        int temp = m * 10;
        if(h <= temp)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}


