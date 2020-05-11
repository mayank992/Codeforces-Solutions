#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
#define umap	 unordered_map
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int n = str.length();
    int temp;
    for(int i = 0; i < n; i++) {
        temp = str[i] - '0';
        if(temp % 8 == 0) {
            cout << "YES\n" << temp;
            return 0;
        }
        for(int j = i+1; j < n; j++) {
            temp = temp * 10 + (str[j] - '0');
            if(temp % 8 == 0) {
                cout << "YES\n" << temp;
                return 0;
            }   
            for(int k = j+1; k < n; k++) {
                temp = temp * 10 + (str[k] - '0');
                if(temp % 8 == 0) {
                    cout << "YES\n" << temp;
                    return 0;
                }
                temp /= 10;
            }
            temp /= 10;
        }
        temp /= 10;
    }   
    cout << "NO";
    return 0;
}


