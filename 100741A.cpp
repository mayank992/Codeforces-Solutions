#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod1 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

ll Table[10][10001] = {0}, Size;

void update(int index, int mod, int value) {
    while(index < Size) {
        Table[mod][index] += value;
        index += (index & (-index));
    }
}

ll count(int index, int mod) {
    ll sum = 0;
    while(index > 0) {
        sum += Table[mod][index];
        index -= (index & (-index));
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    ll arr[10000];
    cin >> n >> m;
    Size = n + 1;
    for(int idx = 0; idx < n; idx++) {
        cin >> arr[idx];
        update(idx + 1, arr[idx] % m, arr[idx]);
    }
    int q, l, r, mod;
    char type;
    cin >> q;
    while(q--) {
        cin >> type >> l >> r;
        if(type == 's') {
            cin >> mod;
            ll result = count(r, mod) - count(l-1, mod);
            cout << result << "\n";
        }
        else if(type == '+') {
            update(l, arr[l-1] % m, -arr[l-1]);
            arr[l-1] += r;
            update(l, arr[l-1] % m, arr[l-1]);
            cout << arr[l-1] << "\n";
        }
        else {
            if(arr[l-1] >= r) {
                update(l, arr[l-1] % m, -arr[l-1]);
                arr[l-1] -= r;
                update(l, arr[l-1] % m, arr[l-1]);
            }
            cout << arr[l-1] << "\n";
        }
    } 
    return 0;
}


