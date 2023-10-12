#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, res[100]{};
    cout << "Enter number: ";
    cin >> n;

    cout << "Prime numbers between 1 and " << n << endl;
    for (int i = 2; i <= n; i++) {
        int flag = 0;
        for (int j = 2; j <= i; j++) {
            if (i % j == 0 && i != j) flag = 1;
        }
        
        if (flag == 0)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}

