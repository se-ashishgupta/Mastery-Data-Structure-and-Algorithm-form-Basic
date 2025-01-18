#include <iostream>
#include <vector>
using namespace std;

// Problem: Find all the leaders in an array.
// A leader is an element which is greater than all the elements to its right.
// For example, in the array {7, 10, 4, 1, 6, 5, 2}, the leaders are 10, 6, and 2.

// Naive Approach to find leaders in the array
// Time Complexity: O(n^2) (Quadratic due to nested loops)
// Auxiliary Space: O(1) (No extra space used)
int LeadersInArrayNaive(vector<int> &arr)
{
    int n = arr.size();

    // Loop through each element in the array
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;

        // Check if any element after the current element is greater
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                isLeader = false; // If a greater element is found, it's not a leader
                break;
            }
        }

        // If no larger element is found, print the current element as a leader
        if (isLeader)
        {
            cout << arr[i] << " "; // Print the leader
        }
    }
}

// Efficient Approach to find leaders in the array
// Time Complexity: O(n) (Linear, as we are traversing the array only once)
// Auxiliary Space: O(1) (No extra space used except for variables)
int LeadersInArrayEfficient(vector<int> &arr)
{
    int n = arr.size();

    // Start with the last element as a leader
    int currLeader = arr[n - 1];
    cout << currLeader << " "; // Print the last element as a leader

    // Traverse the array from the second last element to the first
    for (int i = n - 2; i >= 0; i--)
    {
        // If the current element is greater than the current leader, it's a new leader
        if (arr[i] > currLeader)
        {
            currLeader = arr[i];       // Update the current leader
            cout << currLeader << " "; // Print the new leader
        }
    }
}

int main()
{
    // Example input array
    vector<int> arr = {7, 10, 4, 1, 6, 5, 2};

    // Call the efficient approach to find leaders
    LeadersInArrayEfficient(arr);

    return 0;
}
