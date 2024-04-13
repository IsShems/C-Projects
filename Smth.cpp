#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    long long n, res = 0, h, w, x, y;

    cin >> h >> w >> x >> y;
    cin.ignore();
    vector<vector<string>> chart(h, vector<string>(w));
    string line;
    for (long long i = 0; i < h; i++) {
        getline(cin, line);
        for (long long j = 0; j < w; j++) {
            chart[i][j] = line[j];
        }
    
    }

    if (chart[x - 1][y - 1] == ".") res++;

    if (x != 1) {
        if (chart[x - 2][y - 1] == ".")
            res++;
        if (y != 1) {
            if (chart[x - 2][y - 2] == ".") {
                if (chart[x - 2][y - 1] == "." || chart[x - 1][y - 2] == ".")
                    res++;
            }
            if (chart[x - 1][y - 2] == ".")
                res++;
        }
    }



    if (x != h) {
        if (chart[x][y - 1] == ".")
            res++;
        if (y != w) {
            if (chart[x][y] == ".") {
                if (chart[x][y - 1] == "." || chart[x - 1][y] == ".")
                    res++;
            }
            if (chart[x - 1][y] == ".")
                res++;
        }
    }

    if (x != 1 && y != w && chart[x - 2][y] == ".") {
       if (chart[x - 2][y - 1] == "." || chart[x - 1][y] == ".")
        res++;
    }

    if (x != h && y != 1 && chart[x][y - 2] == ".") {
        if (chart[x - 1][y - 2] == "." || chart[x][y - 1] == ".")
            res++;
    }

    cout << res;
    return 0;
}
