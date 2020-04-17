#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

void get_divisors(vector<int> &divisors, vector<pair<int, int>> &rec_size, int k) {
    pair<int, int> temp;
    for(int i = 1; i <= sqrt(k); i++) {
        if(k % i == 0) {
            if(k/i == i)
                divisors.pb(i);
            else {
                divisors.pb(i);
                divisors.pb(k/i);
            }
            temp.first = i;
            temp.second = k/i;
            rec_size.pb(temp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, R[40000], C[40000];
    cin >> n >> m >> k;
    vector<int> divisors;
    vector<pair<int, int>> rec_size;    
    get_divisors(divisors, rec_size, k);
    for(int i = 0; i < n; i++)
        cin >> R[i];
    for(int i = 0; i < m; i++)
        cin >> C[i];
    unordered_map<int, int> map1, map2;
    int i = 0;
    for(int j = 0; j < n; j++) {
        if(R[j] == 0 || j == n-1) {
            int count;
            if(R[j] == 0)
                count = j - i;
            else if(j == n-1)
                count = n-i;
            if(count > 0) {
                for(int k = 0; k < divisors.size(); k++) {
                    if(divisors[k] <= count)
                        map1[divisors[k]] += count - divisors[k] + 1;
                }
            }
            i = j + 1;
        }   
    }
    i = 0;
    for(int j = 0; j < m; j++) {
        if(C[j] == 0 || j == m-1) {
            int count;
            if(C[j] == 0)
                count = j - i;
            else if(j == m-1)
                count = m - i;
            if(count > 0) {
                for(int k = 0; k < divisors.size(); k++) {
                    if(divisors[k] <= count)
                        map2[divisors[k]] += count - divisors[k] + 1;
                }
            }
            i = j+1;
        }
    }
    ll result = 0;
    for(int i = 0; i < rec_size.size(); i++) {
        int a = rec_size[i].first, b = rec_size[i].second;
        result += (ll)map1[a] * map2[b];
        if(a != b)
            result += (ll)map1[b] * map2[a];
    }
    cout << result << "\n";
    return 0;
}


