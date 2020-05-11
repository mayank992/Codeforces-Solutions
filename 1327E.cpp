#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define mod1 998244353
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()
int _count = 0;

void solve(int n, string str) {
    // if(str.length() > 3) {
    //     if(str[str.length()-3] == str[str.length()-4] && str[str.length()-2] == str[str.length()-3] && str[str.length()-1] == str[str.length()-2])
    //         _count += 1;
    // }
    // // if(str.length() > 2) {
    // //     if(str[str.length()-2] != str[str.length()-3] && str[str.length()-1] == str[str.length()-2])
    // //         _count += 1;
    // // }
    //if(str.length() > 1) {
        if(str[str.length()-1] != str[str.length()-2])
            _count += 1;
    //}
    if(n == 0) {
        return ;
    }
    for(int i = 0; i <= 9; i++) {
        solve(n-1, str + (char )('0' + i));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    solve(n, "");
    cout << _count << "\n"; 
    return 0;
}


