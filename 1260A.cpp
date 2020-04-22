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
    int n;
    cin >> n;
    while(n--) {
        int c, sum;
        cin >> c >> sum;
        if(c == 1)  cout << (sum * sum) << "\n";
        else if(sum == 1)   cout << 1 << "\n";
        else {
            int result = 0;
            while(c != 0) {
                int temp = sum / c;
                result += temp * temp;
                sum -= temp;
                c--;
            }
            cout << result << "\n";
        }
    }
    return 0;
}


