#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Map (key, value) pair - Unique and sorted order - O(logn)
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    mp[1] = 2;
    mp.insert({2, 3});
    mp.emplace(3, 4);

    mp2[{1, 2}] = 3;

    // bgein(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << mp[1] << endl; // 2
    cout << mp[5] << endl; // 0

    auto it = mp.find(1);
    cout << it->second << endl;

    auto it2 = *mp.find(1);
    cout << it2.second << endl;

    auto it3 = mp.lower_bound(1);
    auto it4 = mp.upper_bound(2);

    return 0;
}