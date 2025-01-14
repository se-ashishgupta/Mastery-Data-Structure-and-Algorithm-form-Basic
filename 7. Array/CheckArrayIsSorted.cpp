#include <iostream>
using namespace std;

// Function to check if the array is sorted using a naive approach
// Time Complexity: O(n*n) (Quadratic due to nested loops)
// Auxiliary Space: O(1) (No extra space used)
bool checkSortedNaive(int arr[], int n)
{
    // Loop through each element of the array
    for (int i = 0; i < n; i++)
    {
        // Compare the current element with every element after it
        for (int j = i + 1; j < n; j++)
        {
            // If any later element is smaller, the array is not sorted
            if (arr[j] < arr[i])
            {
                return false; // Return false immediately if not sorted
            }
        }
    }

    // If no such pair is found, the array is sorted
    return true;
}

// Optimized function to check if the array is sorted
// Time Complexity: O(n) (Linear, only one loop)
// Auxiliary Space: O(1) (No extra space used)
bool checkSorted(int arr[], int n)
{
    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // If the current element is smaller than the previous one, it's not sorted
        if (arr[i] < arr[i - 1])
        {
            return false; // Return false immediately if not sorted
        }
    }

    // If no such pair is found, the array is sorted
    return true;
}

int main()
{
    // Initialize an array of integers
    int arr[] = {10, 50, 480, 580, 680};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the naive function and print the result
    cout << "Naive Check Result: " << checkSortedNaive(arr, n) << endl;

    // Call the optimized function and print the result
    cout << "Optimized Check Result: " << checkSorted(arr, n) << endl;

    return 0;
}
