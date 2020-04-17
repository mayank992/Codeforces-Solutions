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
    int n, arr[2000];
    cin >> n;
    for(int i = 0; i < 2*n; i++) {
        cin >> arr[i];
    }    
    sort(arr, arr+(2*n));
    int i;
    for(i = 1; i < 2*n; i++) {
        if(arr[i] != arr[i-1])
            break;
    }
    if(i == 2*n)
        cout << "-1";
    else {
        for(int i = 0; i < 2*n; i++)
            cout << arr[i] << " ";
    }
    return 0;
}


