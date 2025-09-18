#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C;
    cin >> C;

    for(int i = 0; i < C; i++)
    {
        int stud_num, stud_ave;
        int count = 0;
        cin >> stud_num;
        vector<int> stud(stud_num);
        int sum = 0;
        for (int j = 0; j < stud.size(); j++)
        {
            cin >> stud[j];
            sum += stud[j];
        }
        stud_ave = sum / stud.size();

        for (auto a : stud)
        {
            if (stud_ave < a)
            {
                count++;
            }
        }
        
        float result = static_cast<float>(count) / static_cast<float>(stud.size()) * 100;
        cout << fixed;
        cout.precision(3);

        cout << result << '%' << '\n';
    }
}