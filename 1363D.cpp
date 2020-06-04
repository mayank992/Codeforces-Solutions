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
#define pii	     pair<int, int>
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

int query(set<int> &s) {
    cout << "? " << s.size() << " ";
    for (int i: s)
        cout << i << " ";
    cout << endl;
    int num;    cin >> num;
    return num;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;   cin >> n >> k;
        vector<vector<int>> subsets;
        umap<int, bool> mappy;
        for (int i = 0; i < k; i++) {
            int m;  cin >> m;
            vector<int> vec(m);
            for (int i = 0; i < m; i++) {
                cin >> vec[i];  mappy[vec[i]] = 1;
            }
            subsets.pb(vec);
        }
        vector<int> vec;
        for (int i = 1; i <= n; i++) {
            if (mappy.find(i) == mappy.end())
                vec.pb(i);
        }
        subsets.pb(vec);
         // ---------------------------------
        // Max of all indices
        int _max = 0;
        cout << "? " << n << " ";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;   cin >> _max;
        // ---------------------------------
        int low = 0, high = k, curMax = 0;
        while (low < high) {
            int mid = (low + high) / 2;
            set<int> s;
            for (int i = low; i <= mid; i++) {
                for (int j: subsets[i])
                    s.insert(j);
            }
            curMax = query(s);
            if (curMax == _max)
                high = mid;
            else 
                low = mid + 1;
        }
        set<int> s;
        int index = low, distinct = 0;
        for (int i = 0; i <= k; i++) {
            if (i == index) continue;
            for (int j: subsets[i])
                s.insert(j);
        }
        distinct = query(s);
        cout << "! ";
        for (int i = 0; i < k; i++) {
            if (i == index)
                cout << distinct << " ";
            else 
                cout << _max << " ";
        }
        cout << endl;
        string result;
        cin >> result;
        if (result == "Incorrect")
            break;
    }
    return 0;
}
