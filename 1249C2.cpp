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
ull pre[40] = {1};
ull pre_sum[40] = {1};

ull solve(ull n) {
    int ns[70] = {0}, count = 0, c = 0;
    ull temp = n;
    while(temp != 0) {
        ns[count] = temp % 3;
        if(ns[count] == 0 || ns[count] == 1)
            c++;
        temp /= 3; 
        count++;
    }
    //cout << c << " " << count << "\n";
    if(c == count)  return n;
    else if(n > pre_sum[count-1])    return pre[count];
    else {
        ull result = 0;
        for(int i = count-1; i > 0; i--) {
            if(result + pre_sum[i-1] == n)
                return result + pre_sum[i-1];
            else if(result + pre_sum[i-1] < n)
                result += pre[i];
        }
        if(result + 1 <= n)
            return result + 1;
        else 
            return result;
    }
}

int main() {
    for(int i = 1; i < 40; i++) {
        pre[i] = pre[i-1] * 3;
        pre_sum[i] = pre_sum[i-1] + pre[i];
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        ull n;
        cin >> n;
        cout << solve(n) << "\n";
    }    
    return 0;
};