#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int* arr2 = new int[30];
    fill(arr2, arr2 + 30, -1);

    for (int i = 0; i < 28; i++)
    {
        int stud;
        cin >> stud;
        arr2[stud - 1] = stud;
    }

    for (int i = 0; i < 30; i++)
    {
        if (arr2[i] == -1)
        cout << i + 1 << '\n';
    }
    delete[] arr2;

}