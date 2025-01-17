#include <iostream>
#include <vector>
#include <string>
using namespace std;

void leftRotateAnArraydNaive(vector<int> &arr)
{
    int n = arr.size();
    int f = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = f;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    leftRotateAnArraydNaive(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}