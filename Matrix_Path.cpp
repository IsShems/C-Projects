#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int c[1000][1000];
int dp[1000][1000];

int main() {
    int n, m;
    cout << "Enter number of rows and columns:";
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter c[" << i << "][" << j << "] = ";
            cin >> c[i][j];
        }
    }

    dp[0][0] = c[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i || j) {   
                dp[i][j] = INT_MIN;    
                                        
                if (i - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + c[i][j]);
                }

                if (j - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + c[i][j]);
                }
            }
        }
    }

    cout << dp[n - 1][m - 1];
}
