#include <iostream>
#include <vector>
#include <string>
using namespace std;

void moveZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[idx++], arr[i]);
        }
    }
}

int main()
{

    vector<int> arr = {8, 5, 0, 10, 0, 20};
    moveZerosToEnd(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}