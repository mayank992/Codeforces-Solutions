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
        string mat[9];
        for(int i = 0; i < 9; i++) {
            cin >> mat[i];
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(mat[i][j] == '1')
                    cout << '9';
                else 
                    cout << mat[i][j];
                    //cout << " ";
            }
            cout << "\n";
        }
    }    
    return 0;
}


