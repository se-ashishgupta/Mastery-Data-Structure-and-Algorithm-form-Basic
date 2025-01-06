#include <iostream>
using namespace std;

void printNto1(int n) // TC: O(n), AS: O(n), Recurrence Relation: T(n) = T(n-1) + O(1)
{

    if (n == 0)
        return;
    cout << n << " ";
    printNto1(n - 1);
}
int main()
{

    printNto1(5);
    return 0;
}