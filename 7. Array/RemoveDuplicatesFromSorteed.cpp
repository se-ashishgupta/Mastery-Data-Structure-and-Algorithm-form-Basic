#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to remove duplicates from a sorted array (Naive Approach)
// Time Complexity: O(n) (Linear, because we loop through the array once)
// Auxiliary Space: O(n) (Additional space for storing the result)
vector<int> removeDuplicatedNaive(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    vector<int> res;    // This vector will store the result without duplicates

    // Step 1: Add the first element of the array to the result
    res.push_back(arr[0]);

    // Step 2: Loop through the rest of the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // If the current element is different from the previous one, add it to the result
        if (arr[i] != arr[i - 1])
        {
            res.push_back(arr[i]);
        }
    }

    return res; // Return the result without duplicates
}

// Function to remove duplicates from a sorted array (Efficient Approach)
// Time Complexity: O(n) (Linear, but done in-place without extra space)
// Auxiliary Space: O(1) (No extra space except for a few variables)
void removeDuplicatedEfficient(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int idx = 0;        // Variable to track the position of the last unique element

    // Step 1: Loop through the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // Step 2: If the current element is different from the last unique element
        if (arr[idx] != arr[i])
        {
            // Move to the next unique position and replace it with the current element
            swap(arr[++idx], arr[i]); // Swap the elements to remove duplicates in-place
        }
    }
    // No need to return anything since the array is modified in place
}

int main()
{
    // Example input array (with duplicates)
    vector<int> arr = {10, 20, 20, 30, 30, 30};

    // Call the efficient function to remove duplicates in place
    removeDuplicatedEfficient(arr);

    // Print the array after removing duplicates
    for (int x : arr) // Loop through the modified array and print each element
    {
        cout << x << " "; // Print each element followed by a space
    }

    return 0; // Exit the program successfully
}
