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
        int n, k, result = 0;
        string str;
        cin >> n >> k;
        cin >> str;
        for(int i = 0; i < (k + 1) / 2; i++) {
            int count[26] = {0};
            for(int j = 0; j < n; j += k) {
                int first = j + i, second = j + k - i - 1;
                count[str[first] - 'a']++;
                if(first == second)
                    continue;
                count[str[second] - 'a']++;
            }
            int _max = 0;
            for(int j = 0; j < 26; j++) {
                if(count[j] > _max)
                    _max = count[j];
            }
            if((k & 1) && i == k / 2)
                result += (n / k) - _max;
            else 
                result += (2 * (n / k)) - _max;
        }
        cout << result << "\n";
    }    
    return 0;
}


