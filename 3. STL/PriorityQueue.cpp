#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Priority Queue
    cout << "MAX HEAP" << endl;
    priority_queue<int> pq; // Max Heap by default Internally Tree is maintained max value is on top
    pq.push(1);             //  O(logn)
    pq.push(2);
    pq.emplace(3);

    cout << pq.top() << endl;

    pq.pop(); // O(logn)

    cout << pq.top() << endl; // O(1)
    cout << pq.empty() << endl;

    cout << "MIN HEAP" << endl;
    priority_queue<int, vector<int>, greater<int>> pq1; // Min Heap Min value is on top
    pq1.push(1);                                        // {1}
    pq1.push(2);                                        // {1,2}
    pq1.emplace(3);                                     // {1,2,3}

    cout << pq1.top() << endl;

    pq1.pop();

    cout << pq.top() << endl;
    cout << pq.empty();
    return 0;
}