#include <bits/stdc++.h>
using namespace std;

int main()
{
    // SET - Unique and sorted order - O(logn)
    set<int> s;
    s.insert(1);  // {1}
    s.insert(2);  // {1,2}
    s.emplace(1); // {1,2}
    s.emplace(5); // {1,2,5}
    s.emplace(3); // {1,2,3,5}

    // bgein(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    auto it = s.find(3);  // return iterator
    auto it1 = s.find(6); // return end iterator - s.end()

    s.erase(2);

    int ct = s.count(1); // return 1 if available otherwise 0

    auto it3 = s.find(1);
    s.erase(it);

    auto it4 = s.find(2);
    auto it5 = s.find(4);
    s.erase(it4, it5);

    cout << s.empty();

    set<int> s1, s2;
    s1.swap(s2);

    auto it6 = s.lower_bound(2);
    auto it7 = s.upper_bound(3);

    return 0;
}