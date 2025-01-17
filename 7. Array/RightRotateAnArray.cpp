#include <iostream>
#include <vector>
#include <string>
using namespace std;

void RightRotateAnArrayNaive(vector<int> &arr)
{
    int n = arr.size();
    int f = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = f;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    RightRotateAnArrayNaive(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}