// 인원수 입력
// 티셔츠 사이즈 입력
// 티셔츠 묶음 단위, 연필 다스 단위 입력
// 묶음 카운팅할 변수  (티셔츠) ,연필은 나누고, 나머지

#include <iostream>

using namespace std;

int main()
{
    int N, T, P;
    int Tcount = 0, Pcount = 0;
    int* Tsize = new int[6];

    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        cin >> Tsize[i];
    }
    cin >> T >> P;

    for (int i = 0; i < 6; i++)
    {
        int temp = 0;
        if( 0 < Tsize[i])
        {
            if (Tsize[i] % T != 0)
            {
                //cout << Tsize[i] / T << endl;
                temp = (Tsize[i] / T) + 1;
            }else
            {
                temp = Tsize[i] / T;
            }
            Tcount += temp;
            //cout << Tcount << endl;
        }
    }
    cout << Tcount << '\n';
    cout << N / P << ' ' << N % P << '\n';
    
    delete[] Tsize;
}