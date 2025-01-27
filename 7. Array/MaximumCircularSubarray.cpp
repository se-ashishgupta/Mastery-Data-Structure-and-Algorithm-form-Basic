#include <iostream>
#include <vector>

using namespace std;

int MaximumCircularSubarrayNaive(vector<int> &arr)
{
    int n = arr.size();

    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            int circIndex = (i + j) % n;
            sum += arr[circIndex];
            res = max(res, sum);
        }
    }

    return res;
}

int main()
{
    vector<int> arr{5, -2, 3, 4};
    int maxSum = MaximumCircularSubarrayNaive(arr);
    cout << "Maximum sum of a circular subarray is " << maxSum << endl;
    return 0;
}