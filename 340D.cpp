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

class DS {
    private:
        int *Table;
        int Size;    
    public:
        DS(int size) {
            Table = new int[size + 1]{0};
            Size = size + 1;
        }

        int getSum(int index) { // Time Complexity : O(log2n)
            int result = 0;
            while(index > 0) {
                result = max(result, Table[index]);
                index -= (index & (-index));
            }
            return result;
        }

        void update(int index, int value) { // Time Complexity : O(log2n)
            while(index < Size) {
                Table[index] = max(Table[index], value);
                index += (index & (-index));
            }
        }

        void print() {
            for(int i = 0; i < Size; i++)
                cout << Table[i] << " ";
            cout << "\n";
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector<pair<int, int>> arr;
    DS B(n);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.pb(mp(temp, (i+1)));
    }
    sort(all(arr), [](pair<int, int> &a, pair<int, int> &b) {return a.ff < b.ff;});
    for(int i = 0; i < n; i++) {
        B.update(arr[i].ss, B.getSum(arr[i].ss-1) + 1);
        B.print();
    }
    cout << B.getSum(n);
    return 0;
}

// int search(vector<int> &arr, int l, int h, int key) {
//     while(l <= h) {
//         int mid = l + (h - l) / 2;
//         if(arr[mid] == key)
//             return mid;
//         else if(key < arr[mid])
//             h = mid - 1;
//         else 
//             l = mid + 1;
//     }
//     return l;
// }

// int main() {
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout); 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, result = -1;
//     cin >> n;
//     vector<int> arr(n), mem(n);
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     for(int i = 0; i < n; i++) {
//         int idx = search(mem, 0, result, arr[i]);
//         if(idx > result)
//             result++;
//         mem[idx] = arr[i];
//     }
//     cout << result + 1;
//     return 0; 
// }


