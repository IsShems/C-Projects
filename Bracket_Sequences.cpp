#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int res = 0;

    for (int i = 0; i <= line.length(); i++) {
        if (line[i] == '(') res++;
        else if (line[i] == ')') res--;

        if (res < 0) 
            break;
    }

    if (res == 0)
        cout << "true";
    else 
        cout << "false" << endl;
}

