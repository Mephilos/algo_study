#include <iostream>
#include <string>

using namespace std;

// int main()
// {
//     int inputNum;
//     cin >> inputNum;

//     for(int i = 1; i <= inputNum; i++)
//     {
//         cout << i << '\n';
//     } 
// }

int main()
{
    int input_num;
    cin >> input_num;

    string output_num;
    output_num.reserve(input_num * 7); // 공백 문자 + 6자리 숫자를 넣을 메모리 할당
    for(int i = 1; i <= input_num; i++)
    {
        output_num += to_string(i);
        output_num += '\n';
    }
    cout << output_num;
}