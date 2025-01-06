#include <iostream>
using namespace std;

void print1ToN(int n) // TC: O(n), AS: O(n), Recurrence Relation: T(n) = T(n-1) + O(1)
{

    if (n == 0)
        return;
    print1ToN(n - 1);
    cout << n << " ";
}

int main()
{

    print1ToN(5);
    return 0;
}