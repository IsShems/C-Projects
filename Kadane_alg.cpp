#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& profits) {
    int maxEndingHere = profits[0];
    int maxSoFar = profits[0];

    for (int i = 1; i < profits.size(); i++) {
        maxEndingHere = max(profits[i], maxEndingHere + profits[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    int n;
    cin >> n;
    vector<int> profits(n);

    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    int result = maxProfit(profits);
    cout << result << endl;

    return 0;
}


