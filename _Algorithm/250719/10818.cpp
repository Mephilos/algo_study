#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;

    cin >> num;

    int* arr = new int[num];

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int min = arr[0], max = arr[0];
    for (int i = 0; i < num; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << min << ' ' << max << '\n';

    delete[] arr;
}