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
int LPS[1000000];

void computeLPS(string &str, int n) {
    LPS[0] = 0;
    int j = 0, i = 1;
    while(i < n) {
        if(str[i] == str[j])
            LPS[i++] = ++j;
        else {
            if(j != 0)
                j = LPS[j-1];
            else 
                LPS[i++] = 0;
        }
    }
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int n = str.length();
    computeLPS(str, n);
    int key = LPS[n-1], count = 0;
    for(int i = 0; i < n-1; i++) {
        if(LPS[i] == key)
            count++;
    }
    if(LPS[n-1] == 0) {
        cout << "Just a legend";
        return 0;
    }
    if(count)
        cout << str.substr(0, key);
    else {
        if(LPS[LPS[n-1]-1] != 0) 
            cout << str.substr(0, LPS[LPS[n-1]-1]);
        else 
            cout << "Just a legend";
    }
    return 0;
}


