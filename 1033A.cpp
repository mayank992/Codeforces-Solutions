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
    int n, a1, a2, b1, b2, c1, c2;
    cin >> n;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    if(((b1 < a1 && c1 < a1) || (b1 > a1 && c1 > a1)) && ((b2 < a2 && c2 < a2) || (b2 > a2 && c2 > a2)))
        cout << "YES";
    else 
        cout << "NO\n";
    return 0;
}


