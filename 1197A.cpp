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
    int     t;
    cin >> t;
    while(t--) {
        int n, temp, max1 = 0, max2 = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            if(temp > max1) {
                max2 = max1;
                max1 = temp;
            }
            else if(temp > max2) {
                max2 = temp;
            }
        }
        //cout << max1 << " "<< max2 << "\n";
        max1 = min(max1, max2) - 1;
        cout << min(n-2, max1) << "\n";
    }
    return 0;
}


