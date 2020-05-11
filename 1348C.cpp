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

bool isEqual(string &str) {
    for(int i = 0; i < str.length()-1; i++)
        if(str[i] != str[i+1])
            return 0;
    return 1;
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string str, a, b;
        cin >> n >> k;
        cin >> str;
        sort(all(str));
        if(k == 1)
            cout << str << "\n";
        else if(str[0] != str[k-1])
            cout << str[k-1] << "\n";
        else {
            cout << str[k-1];
            string left = str.substr(k);
            if(left == "") {
                cout << "\n";
                continue;
            }
            if(isEqual(left)) {
                for(int i = 0; i < ceil((float)left.length() / k); i++)
                    cout << left[i];
                cout << "\n";
            }
            else    
                cout << left << "\n";
        }
    }    
    return 0;
}
