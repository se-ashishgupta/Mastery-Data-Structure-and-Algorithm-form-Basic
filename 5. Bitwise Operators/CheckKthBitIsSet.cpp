#include <iostream>
using namespace std;

// Using Right Sift
bool checkKthBitSet(int n, int k) // O(1)
{
    return (n >> (k - 1)) & 1;
}

// Using Left Sift
bool checkKthBitSet1(int n, int k) // O(1)
{
    return (1 << (k - 1)) & n;
}

int main()
{

    cout << checkKthBitSet1(8, 1);

    return 0;
}