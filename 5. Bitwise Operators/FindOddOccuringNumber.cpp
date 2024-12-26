#include <iostream>
#include <vector>
using namespace std;

// I/P = vector<int> arr = {4, 3, 4, 4, 4, 5, 5};
// O/p = 3

void oddOccuringNumberNaive(vector<int> arr) // TC= O(n*n) SC = O(1)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
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

int oddOccuringNumber(vector<int> arr) // TC = O(n) SC = O(1)
{

    int res = 0;

    for (int x : arr)
    {
        res = res ^ x;
    }

    return res;
}
int main()
{
    vector<int> arr = {4, 3, 4, 4, 4, 5, 5};
    oddOccuringNumberNaive(arr);
    // cout << oddOccuringNumber(arr) << endl;

    return 0;
}