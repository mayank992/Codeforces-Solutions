#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, arr[200000], temp;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i]; 
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] -= temp;
    }
    sort(arr, arr+n);
    long long int result = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] <= 0)
            continue;
        int idx = upper_bound(arr, arr+n, (-1 * arr[i])) - arr;
        result += i - idx;
    }
    cout << result;
    return 0;
}
