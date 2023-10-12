#include <iostream>
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int people, bill[100];
    cout << "How many people want to order? -> ";
    cin >> people;
    cout << endl;
    double price, summ = 0, count;
    int i = 0, order, flag = 0;

    while(people != 0)
    {
        cout << "\t  MENU:\n\n";
        cout << "Food\nPizza - \"margarita\"\t\t $ 5.99 --> 1";
        cout << "\nPizza - \"hawaiian\"\t\t $ 4.50 --> 2";
        cout << "\nFrench fries\t\t\t $ 2.60 --> 3";
        cout << "\nChicken nuggets\t\t\t $ 3.05 --> 4";
        cout << "\nBurger -\"cheese burger\"\t\t $ 5.05 --> 5";
        cout << "\nPasta\t\t\t\t $ 8.05 --> 6\n"; 
        cout << "\nDesserts\nIce-cream - \"Vanilla\"\t\t $ 1.00 --> 7";
        cout << "\nCake - \"tiramisu\"\t\t $ 5.50 --> 8";
        cout << "\n\nDrinks\nCoca Cola\t\t\t $ 1.50 --> 9";
        cout << "\nFanta\t\t\t\t $ 1.00 --> 10";
        cout << "\nWater\t\t\t\t $ 3.00 --> 11";
        cout << "\n\nWrite number what you what to order and how many of them:";
        cout << "\nP.S. when you finish your order write \"0 0\"...\n";

        
        order = 1;
        while (order != 0)
        {
            cin >> order >> count;
            switch (order)
            {
            case 1:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 5.99 * count;
                break;
            case 2:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 4.5 * count;
                break;
            case 3:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 2.6 * count;
                break;
            case 4:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 3.05 * count;
                break;
            case 5:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 5.05 * count;
                break;
            case 6:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 8.05 * count;
                break;
            case 7:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += count;
                break;
            case 8:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 5.5 * count;
                break;

            case 9:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 1.5 * count;
                break;
            case 10:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2; 
                summ += count;
                break;
            case 11:
                bill[i] = order;
                bill[i + 1] = count;
                i += 2;
                summ += 3 * count;
                break;
            }
        }
        people--;
    }


    int orders = i, j;

    cout << "\n\t\tBILL:\n" << endl;
    for (i = 1; i <= 11; i++)
    {
        count = 0;
        for (j = 0; j < orders; j += 2)
        {
            if (bill[j] == i)
            {
                count += bill[j + 1];
            }
        }

        if (count != 0)
        {
            switch (i)
            {
            case 1:
                cout << "\nPizza - \"margarita\"\t\t" << count << "  $ 5.99\n";
                break;
            case 2:
                cout << "\nPizza - \"hawaiian\"\t\t" << count << "  $ 4.50\n";
                break;
            case 3:
                cout << "\nFrench fries\t\t\t" << count << "  $ 2.60\n";
                break;
            case 4:
                cout << "\nChicken nuggets\t\t\t" << count << "  $ 3.05\n";
                break;
            case 5:
                cout << "\nBurger -\"cheese burger\"\t\t" << count << "  $ 5.05\n";
                break;
            case 6:
                cout << "\nPasta\t\t\t\t" << count << "  $ 8.05\n";
                break;
            case 7:
                cout << "\nIce-cream - \"Vanilla\"\t\t" << count << "  $ 1.00\n";
                break;
            case 8:
                cout << "\nCake - \"tiramisu\"\t\t" << count << "  $ 5.50\n";
                break;
            case 9:
                cout << "\nCoca Cola\t\t\t" << count << "  $ 1.50\n";
                break;
            case 10:
                cout << "\nFanta\t\t\t\t" << count << "  $ 1.00\n";
                break;
            case 11:
                cout << "\nWater\t\t\t\t" << count << "  $ 3.00\n";
                break;
            }
        }
    }
    cout << "\n- - - - - - - - - - - - - - - - - - - - - -\ntotal\t\t\t\t   $ " << summ << endl;
    

	return 0;
}
