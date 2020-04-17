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
    int n, a, b, arr[20];
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    int result = 0;
    int i = 0, j = n-1;
    while(i <= j) {
        if(arr[i] != arr[j]) {
            if(arr[i] == 2)
                result += (arr[j] == 0)? a: b;
            else if(arr[j] == 2)
                result += (arr[i] == 0)? a: b;
            else {
                cout << -1;
                return 0;
            }
        }
        else {
            if(i != j && arr[i] == 2) {
                result += (2 *min(a, b));
            }
            else if(i == j && arr[i] == 2) {
                result += min(a, b);
            }
        }
        i++;
        j--;
    }
    if(i > j)
        cout << result;
    return 0;
}


