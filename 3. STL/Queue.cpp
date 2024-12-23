#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Queue (FIFO)
    queue<int> q;
    q.push(1);    // {1}
    q.push(2);    // {1,2}
    q.emplace(3); // {1,2,3}

    q.back() += 5;

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();

    cout << q.front() << endl;
    cout << q.back() << endl;

    cout << q.empty();

    queue<int> q1, q2;
    q1.swap(q2);

    // size, swap, empty same as stack

    return 0;
}