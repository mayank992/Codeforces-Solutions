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
    int n, arr[300000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    sort(arr, arr+n);
    ll result;
    int i = 0, j = n-1;
    while(i < j) {
        result += pow((ll)(arr[i++] + arr[j--]), 2);
    }
    cout << result;
    return 0;
}


