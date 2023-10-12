#include <iostream>
#include <cstdio>
using namespace std;

int fib(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, res;
    cin >> n;

    res = fib(n);

    cout << res << endl;
}

