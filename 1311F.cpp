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
#define pii      pair<int, int>
#define umap	 unordered_map
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;
const int MAX  =  1e8;

struct d {int value = 0;};
class BinaryIndexedTree {
    private:
        int Size;
        umap<int, d> Table;
    public:
        BinaryIndexedTree(int size): Size(size+1) {}
        int getSum(int index) {
            int sum = 0;
            while(index > 0) {
                sum += Table[index].value;
                index -= (index & (-index));
            }
            return sum;
        }
        void update(int index, int value) {
            while(index < Size) {
                Table[index].value += value;
                index += (index & (-index));
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, pos_max = 0, neg_max = INT_MIN;
    cin >> n;
    vector<pii> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i].ff;
    }
    for(int i = 0; i < n; i++) {
        cin >> vec[i].ss;
        if(vec[i].ss < 0)   neg_max = min(neg_max, vec[i].ss);
        else    pos_max = max(pos_max, vec[i].ss);
    }
    sort(all(vec), [](pii a, pii b) {return (a.ff < b.ff);});
    BinaryIndexedTree pos(MAX), neg(MAX);
    int neg_count = 0, result = 0;
    for(int i = 0; i < n; i++) {
        if(vec[i].ss < 0) {
            int count = neg.getSum(MAX) - neg.getSum(abs(vec[i].ss) - 1);
            result += count;
            neg.update(abs(vec[i].ss), 1);
            neg_count++;
        }
        else {
            int count = ((vec[i].ss == 0)? 0: pos.getSum(vec[i].ss));
            result += neg_count + count;
            pos.update(vec[i].ss, 1);
        }
    }
    cout << result;
    return 0;
}


