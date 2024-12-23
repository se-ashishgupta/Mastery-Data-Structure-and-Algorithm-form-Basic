#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Lower Upper Bound - O(logn)
    int n = 8;

    int arr[n] = {14, 15, 85, 96, 32, 56, 85, 96};

    auto low1 = lower_bound(arr, arr + n, 14);         // return iterator // return equal value if it is exist otherwise return just greater than that value if present in array if not vailable return end iterator
    int index1 = lower_bound(arr, arr + n, 100) - arr; // return index

    auto up2 = upper_bound(arr, arr + n, 14);          // return iterator // return always just greater than that value if present in array if not vailable return end iterator
    int index2 = upper_bound(arr, arr + n, 100) - arr; // return index

    vector<int> v = {14, 15, 85, 96, 32, 56, 85, 96};

    auto low2 = lower_bound(begin(v), end(v), 14);                 // return iterator // return equal value if it is exist otherwise return just greater than that value if present in vector if not vailable return end iterator
    int index3 = lower_bound(v.begin(), v.end(), 100) - v.begin(); // return index

    auto up2 = upper_bound(v.begin(), v.end(), 14);                // return iterator // return always just greater than that value if present in vector if not vailable return end iterator
    int index4 = upper_bound(v.begin(), v.end(), 100) - v.begin(); // return index

    cout << index1;
    return 0;
}