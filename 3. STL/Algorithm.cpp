#include <bits/stdc++.h>
using namespace std;
// MyOwn Comperator
bool comp(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    // they are same
    if (p1.first > p2.first)
        return true;

    return false;
}

int main()
{
    // Algorithm

    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);                 // ascending order
    sort(arr, arr + n, greater<int>()); // descending order   //greater<int>() basically its a comperator

    vector<int> v;
    sort(v.begin(), v.end());                 // ascending order
    sort(v.begin(), v.end(), greater<int>()); // descending order

    int n1 = 3;
    pair<int, int> arr1[n1] = {{1, 2}, {2, 1}, {4, 1}};

    // sort it accroding to second element
    //  if second element is same , then sort it according to first element but in descending

    sort(arr1, arr1 + n1, comp);

    for (auto x : arr1)
    {
        cout << x.first << " " << x.second << endl;
    }

    int num = 7;
    int count = __builtin_popcount(num); // get no of set bit
    cout << count << endl;

    long long num1 = 7;
    int count1 = __builtin_popcountll(num1); // get no of set bit for large number
    cout << count1 << endl;

    int maxi = *max_element(arr, arr + n);
    int maxi = *max_element(begin(v), end(v));

    return 0;
}