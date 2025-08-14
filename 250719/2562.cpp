#include <iostream>

using namespace std;

int main()
{
    int* arr = new int[9];
    int maxNum = 0;
    int num = 0;
    
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (maxNum < arr[i])
        {
            maxNum = arr[i];
            num = i + 1;
        }
    }
    
    cout << maxNum << '\n' << num << '\n';
    delete[] arr;
}