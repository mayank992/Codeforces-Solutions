#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        unordered_map<int ,int> mappy;
        int n, temp, distinct = 0, max_equal = 1;
        cin >> n;
        for(int i = 0; i < n; i++) { 
            cin >> temp;
            if(mappy[temp] == 0) {
                distinct++;
                mappy[temp] = 1;
            }
            else {
                mappy[temp] += 1;
                if(mappy[temp] > max_equal)
                    max_equal = mappy[temp];
            }
        }
        distinct -= 1;
        cout << distinct << " " << max_equal << "\n";
        if(distinct >= max_equal)
            cout << max_equal << "\n";
        else {
            if(distinct == max_equal-1)
                cout << distinct << "\n";
            else 
                cout << distinct + 1 << "\n";
        }
    }    
    return 0;
}


