#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, count = 0, len = 1;
    char prev = '\0';
    string str;
    cin >> n >> k;
    cin >> str;
    sort(str.begin(), str.end());
    prev = str[0];
    count += str[0] - 'a' + 1;
    for(int i = 1; len < k && i < str.length(); i++) {
        if(str[i] > prev+1) {
            prev = str[i];
            len++;
            count += str[i] - 'a' + 1;
        }
    }
    if(len == k)
        cout << count;
    else 
        cout << -1;
    return 0;
}


