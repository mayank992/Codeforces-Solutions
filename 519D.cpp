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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[26];
    for(int i = 0; i < 26; i++)
        cin >> arr[i];
    string str;
    cin >> str;
    int n = str.length(); 
    umap<ll, vector<int>> m;   
    ll cur_sum = 0, result = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 && str[i-1] == str[i]) result++;
        cur_sum += arr[str[i] - 'a'];
        if(m.find(cur_sum) != m.end()) {
            if(i + 1 < n)
                result += m[cur_sum][str[i+1] - 'a'];
            m[cur_sum][str[i] - 'a']++;
            continue;
        }
        vector<int> vec(26, 0); vec[str[i] - 'a']++;
        m[cur_sum] = vec;
    }
    cout << result;
    return 0;
}
