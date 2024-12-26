#include <iostream>
#include <vector>
using namespace std;

// I/P = vector<int> arr = {1, 4, 3};
// O/p = 2
// I/P = vector<int> arr = {1, 5, 3, 2};
// O/p = 4

int findMissingNumberNaive(vector<int> arr) // TC= O(n+2) SC = O(n+2)
{
    int n = arr.size();
    vector<bool> res(n + 2, false);
    for (int i = 0; i < n; i++)
    {
        res[arr[i]] = true;
    }

    for (int i = 1; i < res.size(); i++)
    {
        if (!res[i])
            return i;
    }
}

int findMissingNumber(vector<int> arr) // TC = O(n+1) SC = O(1)
{

    int size = arr.size();
    int res = 0;

    for (int i = 1; i <= size + 1; i++)
    {
        res = res ^ i;
    }

    for (int x : arr)
    {
        res = res ^ x;
    }

    return res;
}
int main()
{
    vector<int> arr = {1, 4, 2};
    cout << findMissingNumberNaive(arr);
    // cout << oddOccuringNumber(arr) << endl;

    return 0;
}