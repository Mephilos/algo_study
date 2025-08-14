#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> T(N + 1);
    vector<int> P(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    vector<int> dp(N + 2, 0);

    int maxProfit = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        maxProfit = max(maxProfit, dp[i]); // 일단 수익 바로 계산(처음이면 초기화의 역할)
        
        // i가 N일을 넘어가는 상담은 불가함.
        if (i > N)
        {
            continue;
        }
        // 마지막 날 채크
        int endDay = i + T[i];

        // 상담이 가능 했을 경우 수익 갱신
        if (endDay <= N + 1)
        {
            // 현재 최대 수익 + 이번 상담 수익과 기존에 계산된 endDay의 수익 중 더 큰 값 
            dp[endDay] = max(dp[endDay], maxProfit + P[i]);
        }
    }
    cout << maxProfit << '\n';
}