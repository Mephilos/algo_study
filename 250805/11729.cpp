#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 1) {
		cout << from << " " << to << endl;
		
	} else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << endl;
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, count = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        count *= 2;
    }
    cout << count - 1 << '\n';

    hanoi(N, 1, 2, 3);
}