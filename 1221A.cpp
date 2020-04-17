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
    int t;
    cin >> t;
    while(t--) {
        int n, temp;
        cin >> n;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            if(temp <= 2048)
                sum += temp;
        }    
        if(sum >= 2048)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}


