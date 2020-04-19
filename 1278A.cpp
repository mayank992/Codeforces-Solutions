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
        string p, h;
        cin >> p >> h;
        int prefix_h[101][26] = {0};
        vector<int> prefix_p(26, 0);
        bool result = false;
        for(int i = 0; i < p.length(); i++)
            prefix_p[(int )p[i] - 'a']++;
        for(int i = 0; i < h.length(); i++) {
            for(int j = 0; i > 0 && j < 26; j++)
                prefix_h[i][j] += prefix_h[i-1][j];
            prefix_h[i][(int )h[i] - 'a']++;
        }
        for(int i = 0, j = p.length()-1; j < h.length(); i++, j++) {
            vector<int> cur(26, 0);
            for(int k = 0; k < 26; k++) {
                cur[k] += prefix_h[j][k] - ((i == 0)? 0: prefix_h[i-1][k]);
            }
            if(prefix_p == cur) {
                result = true;
                break;
            }
        }
        if(result)  cout << "YES\n";
        else    cout << "NO\n";
    }   
    return 0;
}


