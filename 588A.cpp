#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

class _data {
    public:
        int price, day;
};

bool cmp(const _data& a, const _data& b) {
    return a.price < b.price;
}

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, p, need[100001];
    _data obj[100000], price;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> need[i] >> obj[i].price;
        obj[i].day = i;
    }
    need[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        need[i] += need[i+1];
    }
    sort(obj, obj+n, cmp);
    int limit = n;
    ll result = 0;
    for(int i = 0; i < n; i++) {
        if(obj[i].day < limit) {
            result += (need[obj[i].day] - need[limit]) * obj[i].price;
            limit = obj[i].day;
        }
    }
    cout << result;
    return 0;
}


