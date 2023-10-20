#include <iostream>
using namespace std;

void Division(int& n, int primeNum) {
    int Pow = 0;
    while (n % primeNum == 0) {
        Pow++;
        n /= primeNum;
    }
    cout << primeNum;
    if (Pow > 1)
        cout << "^" << Pow;
}

int main() {
    int n, flag = 0;
    cin >> n;

    if (n <= 1) {
        cout << n;
        return 0;
    }

    for (int primeNum = 2; primeNum * primeNum <= n; primeNum++) {
        while (n % primeNum == 0) {
            if (flag == 0)
                flag = 1;
            else
                cout << "*";
            Division(n, primeNum);
        }
    }

    if (n > 1) {
        if (flag == 1)
            cout << "*";
        cout << n;
    }

    return 0;
}
