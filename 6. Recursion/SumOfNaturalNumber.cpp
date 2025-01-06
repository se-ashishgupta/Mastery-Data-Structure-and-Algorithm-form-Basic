#include <iostream>
using namespace std;

int sumOfNaturalNumber(int n) // TC: O(n), AS: O(n), Recurrence Relation: T(n) = T(n-1) + O(1)
{

    if (n == 0)
        return 0;
    return n + sumOfNaturalNumber(n - 1);
}
int main()
{
    int res = sumOfNaturalNumber(5);
    cout << res;
    return 0;
}