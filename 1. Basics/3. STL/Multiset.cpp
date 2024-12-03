#include <bits/stdc++.h>
using namespace std;

int main()
{
    // SET - Not Unique (Multiple element) and sorted order - O(logn)
    multiset<int> ms;
    ms.insert(1);  // {1}
    ms.insert(2);  // {1,2}
    ms.emplace(1); // {1,1,2}
    ms.emplace(5); // {1,1,2,5}
    ms.emplace(3); // {1,1,2,3,5}

    // bgein(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    ms.erase(1); // erase all 1

    auto it = ms.find(3);  // return iterator
    auto it1 = ms.find(6); // return end iterator - s.end()

    int ct = ms.count(1); // return Number of 1

    auto it2 = ms.find(1);
    ms.erase(it2); // single 1 erased

    auto it3 = ms.find(1);
    // ms.erase(ms.find(1), ms.find(1) + 1); // not Supoorted Range
    ms.erase(it2, next(it3));

    cout << ms.empty();

    return 0;
}