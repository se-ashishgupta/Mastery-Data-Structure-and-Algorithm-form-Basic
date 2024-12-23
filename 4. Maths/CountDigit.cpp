#include <iostream>
using namespace std;

int countDigit(int n)
{
        int sum = 0;
        while (n > 0)
        {
                sum++;
                n = n / 10;
        }
        return sum;
}
int main()
{
        int n = 1254;

        cout << countDigit(n);

        return 0;
}