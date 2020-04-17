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
    int n, arr[200000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    sort(arr, arr+n);
    int j = 1, count = 0;
    for(int i = 0; i < n; i++) {
        if(j <= arr[i]) {
            count += 1;
            j++;
        }
    }
    cout << count << "\n";
    return 0;
}


