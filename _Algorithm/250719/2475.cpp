#include <iostream>
#include <array>
using namespace std;

void SNum(int arr[])
{
    int sum;

    for (int i = 0; i < 5; i++)
    {
        arr[i] *= arr[i];
        sum += arr[i];
    }
    cout << sum % 10 << '\n';
}
int main()
{
    int* arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    SNum(arr);
    delete[] arr;
}