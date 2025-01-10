#include <iostream>
using namespace std;

void generateSubsets(string s, string curr, int i) // For a string length of n are going to be a 2^n subsetS, TC=O(2^n) and SC = O(n)
{
    if (i == s.length())
    {
        cout << curr << " ";
        return;
    }

    generateSubsets(s, curr, i + 1);
    generateSubsets(s, curr + s[i], i + 1);
}
int main()
{
    string s = "abc";
    generateSubsets(s, "", 0);
}