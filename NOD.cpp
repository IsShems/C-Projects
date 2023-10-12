#include <iostream>
#include <cstdio>
using namespace std;

int nod(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    int res, a, b;
    cin >> a >> b;

    res = nod(a, b);

    cout << res << endl;

    return 0;
}

