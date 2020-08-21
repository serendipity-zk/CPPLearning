#include <iostream>
#define N 0
#include <stdexcept>
void ferr();
class bs
{
public:
    virtual void p() = 0;
};
void bs::p()
{
    std::cout << "bs";
}
class next : public bs
{
public:
    virtual void p()
    {
        std::cout << "next";
    };
};

using namespace std;
class myclass
{
private:
    static int sx;

public:
    int x;
    const int y = 3;
};

int myclass::sx = 0;

int main()
{

    set_terminate(ferr);
    myclass myc;
    myclass tws;
    cout << myc.y;
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