#include <iostream>

using namespace std;

// int main()
// {
//     int num1, num2, result;
//     while(true)
//     {
//         cin >> num1 >> num2;
//         if (num1 <= 0 || num1 >=10 || num2 <= 0 || num2 >= 10)
//         {
//             break;
//         }

//         result = num1 + num2;

//         cout << result << '\n';
//     }
// }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;

    while (std::cin >> a >> b) {
        std::cout << a + b << '\n';
    }

    return 0;
}