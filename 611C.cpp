#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int dp[501][501] = {0};

void solve(char mat[500][500], int r, int c) {
    for(int i = 2; i <= r; i++)
        dp[i][1] = dp[i-1][1] + ((mat[i-1][0] == '#' || mat[i-2][0] == '#')? 0: 1);
    for(int i = 2; i <= c; i++) 
        dp[1][i] = dp[1][i-1] + ((mat[0][i-1] == '#' || mat[0][i-2] == '#')? 0: 1);
    for(int i = 2; i <= r; i++) {
        for(int j = 2; j <= c; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if(mat[i-1][j-1] != '#') {
                if(mat[i-1][j-2] != '#')
                    dp[i][j]++;
                if(mat[i-2][j-1] != '#')
                    dp[i][j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char mat[500][500]; 
    int prefix_hor[501][501] = {0}, prefix_ver[501][501] = {0};
    int r, c, q;
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
            // prefix_hor[i+1][j+1] = prefix_hor[i+1][j];
            // prefix_ver[i+1][j+1] = prefix_ver[i][j+1];
            // if(mat[i][j] == '.') {
            //     prefix_hor[i+1][j+1] += 1;
            //     prefix_ver[i+1][j+1] += 1;
            // }
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            prefix_hor[i][j] = prefix_hor[i][j-1];
            prefix_ver[i][j] = prefix_ver[i-1][j];
            int _i = i-1, _j = j-1;
            if(i < r) {
                if(mat[_i][_j] == '.' && mat[_i+1][_j] == '.')
                    prefix_hor[i][j] += 1;
            }
            if(j < c) {
                if(mat[_i][_j] == '.' && mat[_i][_j+1] == '.')
                    prefix_ver[i][j] += 1;
            }
        }
    }
    // for(int i = 0; i <= c; i++) 
    //     prefix_hor[r][i] = prefix_hor[r-1][i];
    // for(int i = 0; i <= r; i++) 
    //     prefix_ver[i][c] = prefix_ver[i][c-1];
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= c; j++) {
            cout << prefix_hor[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= c; j++) {
            cout << prefix_ver[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    solve(mat, r, c);
    cin >> q;
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= c; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    while(q--) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ll result = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
        if(r1 > 1) {
            int empty_cells = prefix_hor[r1-1][c2] - prefix_hor[r1-1][c1-1];
            cout << "e1 " << empty_cells << "\n";
            result -= empty_cells;
        } // upper links
        if(c1 > 1) {
            int empty_cells = prefix_ver[r2][c1-1] - prefix_ver[r1-1][c1-1];
            cout << "e2 " << empty_cells << "\n";
            result -= empty_cells;
        } // left side links
        cout << result << "\n";
    }
    return 0;
}


