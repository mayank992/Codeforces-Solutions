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

string s(string a) {
    if(a.length() & 1)  return a;
    int len = a.length() / 2;
    string b = s(a.substr(0, len)), c = s(a.substr(len));
    if(b < c)   return b + c;
    else    return c + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    string c = s(a), d = s(b);
    cout << c << " " << d << "\n";
    if(c == d)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}

// map<pair<string, string>, bool> mappy;

// bool solve(string a, string b) {
//     if(a.length() & 1) return (a == b);
//     if(mappy.find({a, b}) == mappy.end()) {
//         if(a == b)  return mappy[{a, b}] = 1;
//         int len = a.length() / 2;
//         if(solve(a.substr(0, len), b.substr(0, len)) && solve(a.substr(len), b.substr(len)))
//             return mappy[{a, b}] = 1;
//         if(solve(a.substr(0, len), b.substr(len)) && solve(a.substr(len), b.substr(0, len)))
//             return mappy[{a, b}] = 1;
//     }
//     else {
//         return mappy[{a, b}];
//     }
//     return mappy[{a, b}] = 0;
// }

// int main() { 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     string a, b;
//     cin >> a >> b;
//     if(solve(a, b))
//         cout << "YES";
//     else 
//         cout << "NO";
//     return 0;
// }