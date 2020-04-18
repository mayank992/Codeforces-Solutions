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
    int b, k, digit, count_odd = 0;
    cin >> b >> k;
    for(int i = 0; i < k; i++) {
        cin >> digit;
        if(i < k-1 && (b & 1) && (digit & 1))
            count_odd++;
        if(i == k-1 && digit & 1)
            count_odd++;

    }
    if(count_odd & 1)
        cout << "odd\n";
    else 
        cout << "even\n";
    return 0;
}


