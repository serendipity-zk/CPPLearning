#include <iostream>
using namespace std;
int main()
{
    int x[20]{};
    int t = 0;
    while (cin >> x[t++])
        ;
    t--;
    for (size_t i = 0; i < t; i++)
    {
        cout << x[i] << endl;
    }
}