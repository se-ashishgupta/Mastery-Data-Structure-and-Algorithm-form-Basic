#include <iostream>
using namespace std;

bool palindromeCheck(string &str, int start, int end) // TC: O(n), AS: O(n), Recurrence Relation: T(n) = T(n-1) + O(1)
{

    if (start >= end)
    {
        return true;
    }
    return (str[start] == str[end]) && palindromeCheck(str, start + 1, end - 1);
}
int main()
{

    string a = "ashsa";
    bool res = palindromeCheck(a, 0, a.length() - 1);
    cout << res;
    return 0;
}