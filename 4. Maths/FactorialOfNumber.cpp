#include <iostream>
using namespace std;

// Iterative Solution -- Takes O(n) time and O(1) auxilary space
int factorial(int n)
{

    if (n == 0)
        return 1;

    int f = 1;

    while (n > 0)
    {
        f = f * n;
        n = n - 1;
    }

    return f;
}

// Recursive Solution -- Takes O(n) time and O(n) auxilary space cauise overhead thats why interative solution is efficient
int factorialRecursive(int n)
{
    if (n == 0)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    cout << factorialRecursive(5);

    return 0;
}
