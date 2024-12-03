#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;

    int arr[n] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int x = 9;

    // 1. First Occurence of X in Sorted Array
    // int ind = lower_bound(arr, arr + n, x) - arr;
    // if (ind < n && arr[ind] == x)
    //     cout << ind << endl;
    // else
    //     cout << -1 << endl;

    // 2. Last Occurence of X in Sorted Array
    // int ind = upper_bound(arr, arr + n, x) - arr;
    // ind--;
    // if (ind >= 0 && arr[ind] == x)
    //     cout << ind << endl;
    // else
    //     cout << -1 << endl;

    // 3. Larget Number Smaller than X in Sorted Array
    // int ind = lower_bound(arr, arr + n, x) - arr;
    // ind--;
    // if (ind >= 0)
    //     cout << arr[ind] << endl;
    // else
    //     cout << -1 << endl;

    // 4. Smallest Number greater than X in Sorted Array
    int ind = upper_bound(arr, arr + n, x) - arr;

    if (ind < n)
        cout << arr[ind] << endl;
    else
        cout << -1 << endl;

    return 0;
}