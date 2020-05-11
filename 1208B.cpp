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

bool check(umap<int, int> &mappy) {
    for(auto it = mappy.begin(); it != mappy.end(); it++) {
        if(it -> ss > 1)    return 0;
    }
    return 1;
}

bool is_possible(int arr[], umap<int, int> &mappy, int n, int mid) {
    umap<int, int> mapp = mappy;
    if(mid == 0) {
        if(check(mapp))    return 1;
        else    return 0;
    }
    for(int i = 0; i < mid-1; i++)
        mapp[arr[i]] -= 1;
    for(int i = mid-1; i < n; i++) {
        mapp[arr[i]] -= 1;
        if(i - mid >= 0)
            mapp[arr[i - mid]] += 1;
        if(check(mapp))   return 1;
    }
    return 0;
}

int search(int arr[], umap<int, int> &mappy, int n) {
    int low = 0, high = n-1, result = INT_MAX;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(is_possible(arr, mappy, n, mid)) {
            result = min(result, mid);
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return result; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    umap<int, int> mappy;
    int n, arr[2000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mappy[arr[i]] += 1;
    }
    int result = search(arr, mappy, n);   
    cout << result << "\n"; 
    return 0;
}


