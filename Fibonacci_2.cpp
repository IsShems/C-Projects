#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int fib[100001];

int main() {
    int n;      
    cin >> n;

    fib[1] = fib[2] = 1;    

    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];   
    }

    cout << fib[n];  
}
