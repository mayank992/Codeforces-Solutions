#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = (n * 4) - 3;
    int b = 0;
    if(n == 1 || n == 2)
        b = 0;
    else 
        b = ((n-1)*(n-2))/2;
    cout << a + (b * 4);
    return 0;
}