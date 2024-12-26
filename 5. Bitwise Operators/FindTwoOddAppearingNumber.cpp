#include <iostream>
#include <vector>
using namespace std;

// I/P = vector<int> arr = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
// O/p = 5, 6

void findTwoOddAppearingNumberNaive(vector<int> arr) // TC= O(n*n) SC = O(1)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }
}

void findTwoOddAppearingNumber(vector<int> arr) // TC = O(n+1) SC = O(1)
{

    int n = arr.size();
    int xo = 0, res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
        xo = xo ^ arr[i];
    }

    int sn = xo & ~(xo - 1); // RightMost set bit

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & sn) != 0)
        {
            res1 = res1 ^ arr[i];
        }
        else
        {
            res2 = res2 ^ arr[i];
        }
    }

    cout << res1 << " " << res2;
}
int main()
{
    vector<int> arr = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
    // findTwoOddAppearingNumberNaive(arr);
    findTwoOddAppearingNumber(arr);

    return 0;
}