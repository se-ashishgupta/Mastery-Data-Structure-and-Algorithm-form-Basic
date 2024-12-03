#include <bits/stdc++.h>
using namespace std;

int main()
{
    // STL REVISION

    // Vector = Dynamic Arrays
    vector<int> v;

    v.push_back(1);
    v.emplace_back(1); // This is faster then the push_back

    vector<pair<int, int>> v1;

    v1.push_back({1, 2});
    v1.emplace_back(1, 2); // This understand automatically its pair

    vector<int> v2(5, 100); // By deafult its 0 but i assigned 100 as by default value

    vector<int> v3(5);
    vector<int> v4(v3); // Copy vector of v3

    //    iterator

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << endl;

    vector<int>::iterator it2 = v.end();

    auto it3 = v.rend();
    auto it4 = v.rbegin();

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }

    for (auto i : v)
    {
        cout << i << " ";
    }

    // Erase Function

    // {10,20,12,23}
    v.erase(v.begin() + 1);

    // {10,20,12,23,35}
    v.erase(v.begin() + 2, v.begin() + 4); // {10,20,35}   [start, end) end element not deleted

    // Insert Function

    vector<int> v5(2, 100); // {100, 100}

    v5.insert(v.begin(), 300);       // {300, 100, 100}
    v5.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);                         //{50, 50}
    v5.insert(v5.begin(), copy.begin(), copy.end()); //{50, 50, 300, 10, 10, 100, 100}

    // {50, 50, 300, 10, 10, 100, 100}
    cout << v5.size(); // 7

    // v1 - {10, 20}
    // v2 - {30, 40}
    vector<int> v6 = {10, 20};
    vector<int> v7 = {30, 40};
    v6.swap(v7); // v1 - {30, 40}, v2 - {10, 20}

    v7.clear(); // Erase entire vector

    cout << v7.empty();

    //  lower_bound
    auto low1 = lower_bound(v.begin(), v.end(), 30);
    auto low2 = upper_bound(v.begin(), v.end(), 35);

    return 0;
}