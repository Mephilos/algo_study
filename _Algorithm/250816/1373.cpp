#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    string A,R;
    cin >> A;
    
   while (A.length() % 3 != 0)
   {
        A = "0" + A; 
   }

   for (int i = 0; i < A.length(); i += 3)
   {
        int temp = 0;
        temp += (A[i] - '0') * 4;
        temp += (A[i+1] - '0') * 2;
        temp += (A[i+2] - '0') * 1;

        R += to_string(temp);
   }

   cout << R << '\n';
}