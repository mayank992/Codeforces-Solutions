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
        string result;
        int n, a, b;
        cin >> n >> a >> b;
        for(int i = 0; i < b; i++) 
            result += (char )(i + 'a');
        int limit = n / b;
        for(int i = 0; i < limit; i++)
            cout << result;
        int diff = n - (limit * b);
        for(int i = 0; i < diff; i++)
            cout << result[i];
        cout << "\n";
    }
    return 0;
}


