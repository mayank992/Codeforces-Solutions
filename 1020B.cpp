#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int traverse(int arr[], int visited[], int i) {
    if(visited[i] == 1) {
        return i;
    }
    visited[i] = 1;
    return traverse(arr, visited, arr[i]-1);
}

int main() {
    //freopen("input.in", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[1000], result[1000] = {0};
    cin >> n;    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        int visited[n] = {0};
        cout << traverse(arr, visited, i) + 1 << " ";
    }
    return 0;
}


