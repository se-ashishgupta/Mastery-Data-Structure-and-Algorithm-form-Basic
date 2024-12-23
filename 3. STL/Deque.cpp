#include <bits/stdc++.h>
using namespace std;

int main()
{
    // List
    deque<int> dq;
    dq.push_back(1);     //{1}
    dq.emplace_back(4);  //{1,4}
    dq.push_front(3);    //{3,1,4}
    dq.emplace_front(4); //{4,3,1,4}

    dq.pop_back();  //{4,3,1}
    dq.pop_front(); //{3,1}

    cout << dq.front(); // 3
    cout << dq.back();  // 1

    // rest function same as vector
    // begin, end, rbegin, rend, insert, size, swap

    return 0;
}