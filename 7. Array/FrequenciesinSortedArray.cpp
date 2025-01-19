#include <iostream>
#include <vector>
using namespace std;

// Problem: Given a sorted array, print the frequency of each element in the array.
// Example: For the array {10, 10, 10, 25, 30, 30, 50}, the output should be:
//          10- 3
//          25- 1
//          30- 2
//          50- 1

// Approach: Traverse the array while counting occurrences of each distinct element.
// - If the current element is the same as the previous one, increment the frequency count.
// - If the current element is different, print the frequency of the previous element and reset the count.
// - Handle the last element of the array separately to ensure its frequency is printed.
// Time Complexity: O(n) (Single traversal of the array)
// Auxiliary Space: O(1) (No extra space used)
void frequenciesInSortedArray(vector<int> &arr)
{
    int freq = 1; // Initialize frequency count
    int i = 1;    // Start from the second element
    int n = arr.size();

    // Special case: If the array has only one element, print its frequency
    if (n == 1)
    {
        cout << arr[n - 1] << "- " << 1 << endl;
        return;
    }

    // Traverse the array to count frequencies
    while (i < n)
    {
        // Increment frequency while consecutive elements are the same
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }

        // Print the frequency of the current element
        cout << arr[i - 1] << "- " << freq << endl;

        // Reset frequency and move to the next distinct element
        freq = 1;
        i++;
    }

    // Handle the last element separately if it's distinct
    if (arr[n - 1] != arr[n - 2])
    {
        cout << arr[n - 1] << "- " << 1 << endl;
    }
}

int main()
{
    // Example input array
    vector<int> arr{10, 10, 10, 25, 30, 30, 50};

    // Call the function to print frequencies of elements in the array
    frequenciesInSortedArray(arr);

    return 0;
}
