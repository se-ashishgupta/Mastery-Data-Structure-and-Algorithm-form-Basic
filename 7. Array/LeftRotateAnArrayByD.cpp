#include <iostream>
#include <vector>
#include <string>
using namespace std;

void leftRotateAnArrayByOne(vector<int> &arr)
{
    int n = arr.size();
    int f = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = f;
}
void leftRotateAnArrayByDNaive(vector<int> &arr, int d)
{

    for (int i = 0; i < d; i++)
    {
        leftRotateAnArrayByOne(arr);
    }
}

void leftRotateAnArrayByDEfficient(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // to ignore overrotate
    vector<int> temp(arr.begin(), arr.begin() + d);

    // for (int i = 0; i < d; i++)
    // {
    //     temp.push_back(arr[i]);
    // }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// Reverse Algorithm Method
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void leftRotateAnArrayByDReverse(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // to ignore overrotate

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    leftRotateAnArrayByDEfficient(arr, 4);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}