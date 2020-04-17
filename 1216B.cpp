#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first > b.first);
}

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp1;
    vector<pair<int, int>> data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp1;
        data.pb(mp(temp1, i+1));
    }    
    sort(data.begin(), data.end(), cmp);
    ll result = 0;
    for(int i = 0; i < n; i++) {
        result += (data[i].first * i) + 1; 
    }
    cout << result << "\n";
    for(int i = 0; i < n; i++) {
        cout << data[i].second << " ";
    }
    cout << "\n";
    return 0;
}


