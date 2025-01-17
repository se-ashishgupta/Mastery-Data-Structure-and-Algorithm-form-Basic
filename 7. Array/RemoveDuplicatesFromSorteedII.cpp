#include <iostream>
#include <vector>
#include <string>
using namespace std;

void removeDuplicatedII(vector<int> &arr)
{
    int n = arr.size();
    int idx = 1;
    for (int i = 1; i < n; i++)
    {
        if (idx == 1 || arr[i] != arr[idx - 2])
        {
            swap(arr[idx++], arr[i]);
        }
    }
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 3};
    removeDuplicatedII(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}