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
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, temp; 
    ull first = 0, second = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp > first) {
            second = first;
            first = temp;
        }
        else if(temp > second) {
            second = temp;
        }
    }
    if(first == second) {
        cout << first * m;
    }
    else {
        ull temp1 = ((ull )min(first, second)) * (m / (k+1));
        ull temp2 = ((ull )max(first, second)) * (m - (m/(k+1)));
        cout << temp1 + temp2;
    }
    return 0;
}


