#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, arr[2000], brr[2000];
    cin >> n;   
    int odd = 0, even = 0, temp, i, j;
    while(odd + even < n) {
        cin >> temp;
        if(temp & 1) {
            brr[odd] = temp;
            odd++;
        }
        else {
            arr[even] = temp;
            even++;
        }
    }
    if(abs(odd - even) <= 1) {
        cout << 0;
        return 0;
    }
    long long int sum = 0;
    sort(arr, arr+even);
    sort(brr, brr+odd);
    if(odd < even) {
        i = odd+1;
        j = odd;
    }
    else {
        i = even;
        j = even + 1;
    }
    for(int k = 0; k < even - i; k++)
        sum += arr[k];
    for(int k = 0; k < odd - j; k++)
        sum += brr[k];
    cout << sum;
    return 0;
}


