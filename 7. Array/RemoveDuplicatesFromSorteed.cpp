#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> removeDuplicatedNaive(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    res.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            res.push_back(arr[i]);
        }
    }

    return res;
}

void removeDuplicatedEfficient(vector<int> &arr)
{
    int n = arr.size();
    int idx = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[idx] != arr[i])
        {

            swap(arr[++idx], arr[i]);
        }
    }
}
int main()
{

    vector<int> arr = {10, 20, 20, 30, 30, 30};
    removeDuplicatedEfficient(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}