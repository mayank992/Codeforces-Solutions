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
    int t;
    cin >> t;
    while(t--) {
        int n, arr[200000];
        int vec[200000][201] = {0};
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            vec[i][arr[i]]++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= 200; j++) {
                vec[i][j] += vec[i-1][j];
            }
        }
    }    
    return 0;
}


