#include <iostream>
#define N 0
using namespace std;
int main()
{
    int x[20]{};
    int t = 0;
    const int *const ****p = nullptr;
    const int *const **const *const *const *t2 = &p;
    const int *t3;
    int *t5;
    t5 = N;

    int const *const *t4;
    while (cin >> x[t++])
        ;
    t--;
    for (size_t i = 0; i < t; i++)
    {
        cout << x[i] << endl;
    }
}
int sum(int (*t)[4], int size)
{
    return 0;
}