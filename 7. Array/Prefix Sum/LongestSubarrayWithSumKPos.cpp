#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithSumKNaive(vector<int> &arr, int k)
{

    int res = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}

int longestSubarrayWithSumKEfficent(vector<int> &arr, int k) // using hashmap
{
    // code here
    int n = arr.size();
    int res = 0, sum = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        if (sum == k)
        {
            res = max(res, i + 1);
        }

        if (mp.find(sum - k) != mp.end())
        {
            res = max(res, i - mp[sum - k]);
        }

        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return res;
}

int longestSubarrayWithSumKEfficentSecond(vector<int> &arr, int k) // using two pointer
{
    // code here
    int n = arr.size();
    int res = 0, sum = arr[0];
    int l = 0, r = 0;

    while (r < n)
    {

        while (l <= r && sum > k)
        {
            sum -= arr[l++];
        }

        if (sum == k)
        {
            res = max(res, r - l + 1);
        }

        r++;
        if (r < n)
            sum += arr[r];
    }

    return res;
}

int main()
{

    vector<int> arr = {10, 5, 2, 8, 10};
    int k = 15;

    cout << "Longest Subarry Sum With Sum K is of Length " << longestSubarrayWithSumKEfficentSecond(arr, k);
    return 0;
}