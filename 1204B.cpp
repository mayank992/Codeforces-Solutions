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
    int n, l, r, temp = 1;
    cin >> n >> l >> r;
    vector<int> possiblities;
    while(possiblities.size() < r) {
        possiblities.pb(temp);
        temp*= 2;
    }
    int sum1 = 0, sum2 = 0;
    temp = n;
    while(n != 0 && l != 0) {
        if(l == 1) {
            sum1 += possiblities[l-1];
            n--;
        }
        else {
            sum1 += possiblities[l-1];
            l--;
            n--;
        }
    }    
    n = temp;
    for(int i = 1; i <= n; i++) {
        if(i < r) {
            sum2 += possiblities[i-1];
        }
        else {
            sum2 += possiblities[r-1];
        }
    }
    cout << sum1 <<  " " << sum2;
    return 0;
}


