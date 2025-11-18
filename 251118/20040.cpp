#include <vector>
#include <iostream>

using namespace std;

vector<int> vec;
vector<int> vec2;
int find(int a)
{
    if (vec[a] == a)
    {
        return a;
    }
    return vec[a] = find(vec[a]);
}
void uniSet(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        return;
    }

    if (vec2[a] < vec2[b])
    {
        vec[a] = b;
    }
    else
    {
        vec[b] = a;

        if (vec2[a] == vec2[b])
        {
            vec2[a]++;
        }
    }
}