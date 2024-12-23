#include <bits/stdc++.h>
using namespace std;

int main()
{
    // List (LIFO)
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {1,2}
    st.emplace(3); // {1,2,3}

    cout << st.top() << endl; // 3 st[0] is invalid

    st.pop();

    cout << st.top() << endl; // 2

    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);

    return 0;
}