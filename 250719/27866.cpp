#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int i;
    // cout << "문자 입력" << endl;
    cin >> S;
    
    while (true)
    {
        // cout << "루프문 확인" << endl;
        cin >> i;
        if (S.length() >= i)
        {
           // cout << "루프문 이프 조건" << endl;
            cout << S[i - 1] << '\n';
            return 0;
        }
    }
}