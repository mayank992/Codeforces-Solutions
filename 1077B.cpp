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
    int k = 0, n, arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    for(int i = 1; i < n-1; i++) {
        if(arr[i] == 0 && arr[i-1] == 1 && arr[i+1] == 1) {
            arr[i+1] = 0;
            k++;
        }
    }
    cout << k;
    return 0;
}


