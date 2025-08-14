#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;


void PrintDeque(deque<int>& dq, bool isRvs)
{
    cout << "[";
    if (!isRvs)
    {
        for (int i = 0; i < dq.size(); i++)
        {
            cout << dq[i];
            if (i != dq.size() - 1)
            {
                cout << ",";
            }
        }
    }
    else
    {
        for (int i = dq.size() - 1; i >= 0; i--)
        {
            cout << dq[i];
            if (i != 0)
            {
                cout << ",";
            }
        }
    }
    cout << "]\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T ; i++)
    {
        string func_rd;
        int n;
        string arr_str;

        cin >> func_rd >> n >> arr_str;

        deque<int> dq;
        string num_str = "";

        for (char c : arr_str)
        {
            if (isdigit(c))
            {
                num_str += c;
            }
            else
            {
                if (!num_str.empty())
                {
                    dq.push_back(stoi(num_str));
                    num_str = "";
                }
            }
        }
        bool isRvs = false;
        bool isErr = false;

        for (char cmd : func_rd)
        {
            if (cmd == 'R')
            {
                isRvs = !isRvs;
            }
            else
            {
                if (dq.empty())
                {
                    isErr = true;
                    break;
                }

                if (isRvs)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
        }
        if (isErr)
        {
            cout << "error\n";
        }
        else
        {
            PrintDeque(dq, isRvs);
        }
    }
}