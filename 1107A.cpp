#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

bool is_greater(string& prev, string& next) {
    if(next.length() > prev.length()) 
        return 1;
    else if(next.length() < prev.length())
        return 0;
    else {
        int limit = min(prev.length(), next.length());
        for(int i = 0; i < limit; i++) {
            if(prev[i] < next[i])
                return 1;
            else if(prev[i] > next[i])
                return 0;
        }
        return 0;
    }
    return 0;
}

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, count = 1;
        string str, prev, next;
        cin >> n;
        cin >> str;
        if(n == 2 && str[0] >= str[1]) {
            cout << "NO\n";
            continue;
        }
        prev = str[0];
        vector<string> result;
        result.pb(prev);
        for(int i = 1; i < n; i++) {
            next.pb(str[i]);
            if(is_greater(prev, next)) {
                count++;
                result.pb(next);
                prev = next; 
                next = "";
            } 
        }
        cout << "YES\n" << count << "\n";
        for(auto it = result.begin(); it != result.end(); it++) {
            if(it == result.begin())
                cout << *it;
            else 
                cout << " " << *it;

        }
        if(next != "") {
            cout << next;
            next = "";
        }
        cout << "\n";
    }
    return 0;
}


