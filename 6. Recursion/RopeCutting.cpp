#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int roopCutting(int n, int a, int b, int c)
{

    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int res = max(roopCutting(n - a, a, b, c),
                  max(roopCutting(n - b, a, b, c),
                      roopCutting(n - c, a, b, c)));

    if (res == -1)
        return -1;
    return res + 1;
}
int main()
{

    cout << roopCutting(23, 12, 11, 9);
    return 0;
}