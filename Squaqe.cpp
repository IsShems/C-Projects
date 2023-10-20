#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, val;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int size = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            if (val == 1) {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] += min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                }

                if (dp[i][j] == size) {
                    cnt++;
                }
                if (dp[i][j] > size) {
                    size = dp[i][j];
                    cnt = 1;
                }
            }
        }
    }
    cout << size * cnt << endl;
}
