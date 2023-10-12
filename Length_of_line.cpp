#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    char s[1000];
    cout << "Enter: ";
    gets_s(s);
    puts(s);

    cout << strlen(s) << endl;

    return 0;
}

