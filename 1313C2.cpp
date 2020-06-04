/*
Platform: Codeforces
Problem: Skyscrapers (hard version)
Problem Link: https://codeforces.com/problemset/problem/1313/C2
*/

#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define mem(a,v) memset(a, v, sizeof(a))
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
#define umap	 unordered_map
#define pii		 pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;
const int N = 500001;

void compute(int height[], int p[], int n) {
    // vector<int> vec, index; vec.pb(height[0]); index.pb(0);
    // for (int i = 1; i < n; i++) {
    //     auto it = upper_bound(vec.begin(), vec.end(), height[i]);
    //     if (it == vec.end()) {
    //         vec.pb(height[i]);
    //         p[i] = index.back();
    //         index.pb(i);
    //     }
    //     else {
    //         *it = height[i];
    //         p[i] = p[index[it - vec.begin()]];
    //         index[it - vec.begin()] = i;
    //     }
    // }
    stack<int> st, index;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > height[i]) 
            st.pop(), index.pop();
        if (st.empty()) p[i] = -1;
        else    p[i] = index.top();
        st.push(height[i]), index.push(i);
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  cin >> n; 
    int p[n], height1[n], height2[n];
    ll prev[n], after[n];
    for (int i = 0; i < n; i++) {
        cin >> height1[i];
        height2[n - i - 1] = height1[i];
    }
    mem(p, -1); compute(height1, p, n);
    prev[0] = height1[0];
    for (int i = 1; i < n; i++) {
        prev[i] = height1[i];
        if (p[i] == -1)
            prev[i] += (1LL * i * height1[i]);
        else 
            prev[i] += (1LL * (i - p[i] - 1) * height1[i]) + prev[p[i]];
    }
    mem(p, -1); compute(height2, p, n);
    after[n - 1] = height2[0];
    for (int i = 1; i < n; i++) {
        after[n - i - 1] = height2[i];
        if (p[i] == -1)
            after[n - i - 1] += (1LL * i * height2[i]);
        else 
            after[n - i - 1] += (1LL * (i - p[i] - 1) * height2[i]) + after[n - p[i] - 1];
    }
    ll result = 0;  int peak = 0;
    for (int i = 0; i < n; i++) {
        ll cur = prev[i] + after[i] - height1[i];
        if (cur > result) {
            result = cur;
            peak = i;
        }
    }
    int i = peak - 1, _min = height1[peak];
    while (i >= 0) {
        if (height1[i] <= _min)
            _min = height1[i];
        else 
            height1[i] = _min;
        i--;
    }
    i = peak + 1, _min = height1[peak];
    while (i < n) {
        if (height1[i] <= _min)
            _min = height1[i];
        else 
            height1[i] = _min;
        i++;
    }
    for (int i = 0; i < n; i++)
        cout << height1[i] << " ";
    cout << "\n";
    return 0;
}
