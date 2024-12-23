#include <bits/stdc++.h>
using namespace std;

int main()
{
    // STL REVISION

    // Pairs
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}};

    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    pair<int, int> arr[2] = {{1, 2}, {2, 3}};

    cout << arr[0].first << " " << arr[0].second << endl;

    return 0;
}