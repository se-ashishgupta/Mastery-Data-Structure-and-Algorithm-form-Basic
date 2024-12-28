#include <iostream>
using namespace std;

void pattern1(int n)
{

    if (n == 0)
        return;
    pattern1(n / 2);
    cout << (n % 2);
}

int main()
{

    pattern1(4);
    return 0;
}