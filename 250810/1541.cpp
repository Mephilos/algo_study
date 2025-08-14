#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expression;
    cin >> expression;

    int result = 0;
    string current_num_str = "";
    bool is_minus_section = false; 

    for (int i = 0; i <= expression.length(); i++) {
        char ch = expression[i];

        // 연산자이거나 문자열의 끝이면, 지금까지 쌓인 숫자를 계산
        if (ch == '+' || ch == '-' || i == expression.length()) {
            int num = stoi(current_num_str);
            
            if (is_minus_section) {
                result -= num;
            } else {
                result += num;
            }

            // 현재 연산자가 '-'라면, 마이너스 구간 시작
            if (ch == '-') {
                is_minus_section = true;
            }
            
            // 숫자 문자열 초기화
            current_num_str = "";
        }
        // 숫자이면, 문자열에 추가
        else {
            current_num_str += ch;
        }
    }

    cout << result << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>
// using namespace std;

// vector<string> split(string input, char delimiter);
// int mySum(string a);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int answer = 0;

//     string example;
//     cin >> example;
//     vector<string> str = split(example, '-');
    
//     for (int i = 0; i < str.size();i++)
//     {
//         int temp = mySum(str[i]);
//         if (i == 0)
//         {
//             answer = answer + temp;
//         }
//         else
//         {
//             answer = answer - temp;
//         }
//     }
//     cout << answer << '\n';
// }

// vector<string> split(string input, char delimiter)
// {
//     vector<string> result;
//     stringstream mystream(input);
//     string splitdata;

//     while (getline(mystream, splitdata, delimiter))
//     {
//         result.push_back(splitdata);
//     }
//     return result;
// }

// int mySum(string a)
// {
//     int sum = 0;
//     vector<string> temp = split(a, '+');
//     for (int i = 0; i < temp.size(); i++)
//     {
//         sum += stoi (temp[i]);
//     }
//     return sum;
// }