#include <iostream>
using namespace std;

int permutatioOfString(int arr[], int n, int sum) // For a string length of n are going to be a 2^n subsetS, TC=O(2^n) and SC = O(n)
{
    if (n == 0)
    {
        return sum == 0 ? 1 : 0;
    }

    return permutatioOfString(arr, n - 1, sum) +
           permutatioOfString(arr, n - 1, sum - arr[n - 1]);
}
int main()
{
    int arr[] = {1, 2, 3};
    cout << permutatioOfString(arr, 3, 5);
}