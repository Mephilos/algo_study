#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int* arr0 = new int[41];
    int* arr1 = new int[41];
    arr0[0] = 1;
    arr0[1] = 0;
    arr1[0] = 0;
    arr1[1] = 1;

    for (int j = 2; j < 41; j++)
    {
        arr0[j] = arr0[j - 1] + arr0[j - 2];
        arr1[j] = arr1[j - 1] + arr1[j - 2];
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        cout << arr0[N] << " " << arr1[N] << '\n';
    }
    delete[] arr1;
    delete[] arr0;
}