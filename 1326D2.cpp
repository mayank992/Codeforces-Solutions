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

string computePalindrome(string & str) {
    string pattern = str;
    reverse(all(pattern));
    pattern = str + '#' + pattern;
    int n = pattern.length(), LPS[n], i = 1, j = 0;
    LPS[0] = 0;
    while(i < n) {
        if(pattern[i] == pattern[j])
            LPS[i++] = ++j;
        else {
            if(j != 0)  j = LPS[j-1];
            else    LPS[i++] = 0;
        }
    } 
    return pattern.substr(0, j);
}

void solve(string str) {
    int i = 0, j = str.length()-1;
    while(i < j && str[i] == str[j])
        i++, j--;
    string prefix = str.substr(0, i);
    string middle = str.substr(i, j-i+1);
    string a = computePalindrome(middle);
    reverse(all(middle));
    string b = computePalindrome(middle);
    if(a.length() < b.length()) 
        cout << prefix << b << str.substr(j+1) << "\n";
    else 
        cout << prefix << a << str.substr(j+1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        solve(str);
    }
    return 0;
}


