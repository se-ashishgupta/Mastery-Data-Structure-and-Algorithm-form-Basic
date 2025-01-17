#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void RightRotateAnArrayByOne(vector<int> &arr)
{
    int n = arr.size();
    int f = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = f;
}
void RightRotateAnArrayByDNaive(vector<int> &arr, int d)
{
    for (int i = 0; i < d; i++)
    {
        RightRotateAnArrayByOne(arr);
    }
}

void RightRotateAnArrayByDEfficient(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // to ignore overrotate

    vector<int> temp(arr.end() - d, arr.end());

    for (int i = n - d - 1; i >= 0; i--)
    {
        arr[i + d] = arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }
}

// Reverse Algorithm Method
// void reverse(vector<int> &arr, int start, int end)
// {
//     while (start < end)
//     {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }
void RightRotateAnArrayByDReverse(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // to ignore overrotate

    // reverse(arr, 0, n - 1);
    // reverse(arr, 0, d - 1);
    // reverse(arr, d, n - 1);

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    RightRotateAnArrayByDEfficient(arr, 3);
    // RightRotateAnArrayByDReverse(arr, 3);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}