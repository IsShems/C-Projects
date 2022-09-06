#include <iostream>
using namespace std;

struct Puzzle_15 {
    int rows = 4;
    int cols = 4;

    void vremya() {
        int vremya = 0;
        while (vremya != 300000000)
            vremya++;
    }

    int find(int** arr, int findme)
    {
        int check = 0;
        for (int** i = arr; i < arr + rows; i++)
        {
            for (int* j = *i; j < *i + cols; j++)
            {
                if (findme == *j)
                {
                    check = 1;
                    break;
                }
            }
            if (check == 1)
                break;
        }
        if (check == 0)
            return 0;
        else
            return 1;
    }

    int** create_arr() {
        int** arr = new int* [rows] {};
        int number = 1;

        for (int** i = arr; i < arr + rows; i++)
        {
            *i = new int[cols] {};
        }

        for (int** i = arr; i < arr + rows; i++)
        {
            for (int* j = *i; j < *i + cols; j++)
            {
                if (number == 16)
                    *j = 0;
                else
                    *j = number;
                number++;
            }

        }

        return arr;
    }

    int** mix_arr() { // imenno s ney budet idti igra 

        int** arr_copy = new int* [rows] {};
        int number = 1;

        for (int** i = arr_copy; i < arr_copy + rows; i++)
        {
            *i = new int[cols] {};
        }

        int num = -1;
        for (int** i = arr_copy; i < arr_copy + rows; i++)
        {
            for (int* j = *i; j < *i + cols; j++)
            {
                if (num == -1) {
                    *j = 0;
                    num = 0;
                }
                else
                {
                    do {
                        num = rand() % 16;
                    } while (find(arr_copy, num) == 1);
                    *j = num;

                }
            }

        }

        return arr_copy;
    }

    void print_arr(int** arr) {
        for (int** i = arr; i < arr + rows; i++)
        {
            cout << "-------------\n";
            for (int* j = *i; j < *i + cols; j++)
            {

                if (*j == 0)
                    cout << "|  ";
                else if (*j < 10)
                    cout << "| " << *j;
                else
                    cout << "|" << *j;
            }
            cout << "|\n";
        }
        cout << "-------------\n";


    }

    int find_ind_i(int** arr, int findme) //nahodit i chisla
    {
        int check = 0;
        int index_i = -10;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (findme == arr[i][j])
                {
                    index_i = i;
                    break;
                }
            }
            if (check == 1)
                break;
        }

        return index_i;
    }

    int find_ind_j(int** arr, int findme) // nahofit j chisla
    {
        int check = 0;
        int index_j = -10;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (findme == arr[i][j])
                {
                    index_j = j;
                    break;
                }
            }
            if (check == 1)
                break;
        }

        return index_j;
    }

    void game(int**& arr_copy, int** arr, int start_time) {
        int win = 0, num = 0, change_num, check = 0, for_changing_i, for_changing_j;

        int emp_i = find_ind_i(arr_copy, 0);
        int emp_j = find_ind_j(arr_copy, 0); //ukazivayet na i,j pustuyoy yacheyku


        cout << "\nEnter the number you want to rearrange: ";
        while (win != 1) {
            do {
                cout << "\n-> ";
                cin >> change_num;
                for_changing_i = find_ind_i(arr_copy, change_num);
                for_changing_j = find_ind_j(arr_copy, change_num); //ukazivayet na i,j yacheyki kotoruyu mi perestavlayem

                if (change_num <= 15 && change_num >= 0)
                    check = 1;

                if ((for_changing_i - emp_i <= 1 && for_changing_i - emp_i >= -1) && (for_changing_j - emp_j <= 1 && for_changing_j - emp_j >= -1) && (abs(for_changing_i - emp_i) + abs(for_changing_j - emp_j) != 2)) //dodelat
                    check = 1; // ostalos procontrolirovat chobi tolko sosednii mojno bilo menat
                else
                    check = 0;

            } while (check == 0);


            int tmp = arr_copy[emp_i][emp_j];
            arr_copy[emp_i][emp_j] = arr_copy[for_changing_i][for_changing_j];
            arr_copy[for_changing_i][for_changing_j] = tmp; //menayem mestami znacheniya

            tmp = emp_i;
            emp_i = for_changing_i;
            for_changing_i = tmp;
            tmp = emp_j;
            emp_j = for_changing_j;
            for_changing_j = tmp;//menayem mestami indexsi chobi snova emp ukazival na pustuyu i for_changing na svoyu

            win = 1;
            int** i = arr;
            for (int** i_c = arr_copy; i_c < arr_copy + rows; i_c++) //proverayet vse li stoit na pravilnih mestah
            {
                int* j = *i;
                for (int* j_c = *i_c; j_c < *i_c + cols; j_c++)
                {
                    if (*j != *j_c) {
                        win = 0;
                        break;
                    }
                    j++;
                }
                if (win == 0)
                    break;
                i++;
            }
            print_arr(arr_copy);
        }

        int gaming_time = time(NULL) - start_time;     //kak tolko igra zakanchivayetsa, mi zasekayem vremya potrachinnoye na igru

        cout
            << "\n\nCongratulations!!!\nYou won!" << endl
            << "\ntime: " << gaming_time / 60 << " min " << gaming_time % 60 << " sec" << endl;

    }
};

int main()
{
    Puzzle_15 pz_15;
    srand(time(NULL));
    int** puzzle = pz_15.create_arr();
    cout << "How puzzle suppost to look:\n";
    pz_15.print_arr(puzzle);

    char* mix = new char[9]{ "\nMIX...\n" };
    for (int i = 0; i < 9; i++) {
        pz_15.vremya();
        cout << mix[i];
    }

    pz_15.vremya();
    int** copy_puzzle = pz_15.mix_arr();
    cout << endl;
    pz_15.print_arr(copy_puzzle);

    pz_15.vremya();
    cout << "\nTHE ";
    pz_15.vremya();
    cout << "GAME ";
    pz_15.vremya();
    cout << "BEGIN!\n";

    int start_time = time(NULL);        // zasekayem vremya nachalo igri
    pz_15.game(copy_puzzle, puzzle, start_time);

    return 0;
}
