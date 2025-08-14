#include <iostream>

using namespace std;

int main()
{
    int year;
    bool yoon;
    cin >> year;
    
    if ( year % 400 == 0)
    {
        yoon = true;
    } else if (year % 4 == 0 && year % 100 != 0)
    {
        yoon = true;
    } else
    {
        yoon = false;   
    }
    cout << yoon << endl;
}