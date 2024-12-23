#include <bits/stdc++.h>
using namespace std;

int main()
{
    // List
    list<int> l;
    l.push_back(1);
    l.emplace_back(4);

    l.push_front(3);

    l.emplace_front(4);

    // rest function same as vector
    // begin, end, rbegin, rend, insert, size, swap

    return 0;
}