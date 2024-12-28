#include <iostream>
using namespace std;

void pattern1(int n)
{

    if (n == 0)
        return;
    cout << n << endl;
    pattern1(n - 1);
    cout << n << endl;
}

void pattern2(int n)
{

    if (n == 0)
        return;

    pattern2(n - 1);
    cout << n << endl;
    pattern2(n - 1);
}

int main()
{

    pattern2(3);
    return 0;
}