    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;
        
        cin >> N;

        while(N--)
        {
            string s;
            cin >> s;
            int num = 0, result = 0;
            for (char c : s)
            {
                if (c == 'O')
                {
                    num++;
                    result += num;
                }
                else
                {
                    num = 0;
                }
            }
            cout << result << '\n';
        }
    }