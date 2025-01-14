#include <iostream>
using namespace std;

// Function to find the largest element in the array
// Time Complexity: O(n) (Linear traversal)
// Auxiliary Space: O(1) (No extra space used)
int largestElement(int arr[], int n)
{
    // Initialize max with the first element of the array
    int max = arr[0];

    // Traverse the array from the second element to the end
    for (int i = 1; i < n; i++)
    {
        // Update max if the current element is greater
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Return the largest element found
    return max;
}

// Naive solution to find the second largest element
// Time Complexity: O(2n) = O(n) (Two traversals of the array)
// Auxiliary Space: O(1) (No extra space used)
int secondLargestElementNaive(int arr[], int n)
{
    // If the array has only one element, return -1 as there is no second largest
    if (n == 1)
    {
        return -1;
    }

    // Find the largest element in the array
    int first = largestElement(arr, n);

    // Initialize second largest as -1 (to handle cases with no second largest)
    int second = -1;

    // Traverse the array to find the largest element that is not equal to `first`
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    // Return the second largest element (or -1 if it doesn't exist)
    return second;
}

// Efficient solution to find the second largest element
// Time Complexity: O(n) (Single traversal of the array)
// Auxiliary Space: O(1) (No extra space used)
int secondLargestElement(int arr[], int n)
{
    // Initialize first and second largest as -1
    int first = -1, second = -1;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // If the current element is greater than the current first largest
        if (arr[i] > first)
        {
            // Update second largest to be the current first largest
            second = first;

            // Update first largest to be the current element
            first = arr[i];
        }
        // If the current element is not equal to the first largest
        // but greater than the current second largest
        else if (arr[i] != first && arr[i] > second)
        {
            // Update second largest to the current element
            second = arr[i];
        }
    }

    // Return the second largest element (or -1 if it doesn't exist)
    return second;
}

int main()
{
    // Initialize an array of integers
    int arr[] = {10, 50, 480, 96, 470};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the efficient function to find the second largest element and print the result
    cout << "Second Largest Element (Efficient): " << secondLargestElement(arr, n) << endl;

    return 0;
}
