#include <iostream>
#include <vector>
using namespace std;

// Problem: Given an array of stock prices where each element represents the price of a stock on a specific day,
//          find the maximum profit you can achieve by performing multiple buy-sell transactions.
//          You can buy and sell multiple times, but you must sell the stock before you buy it again.
// Example: For the array {1, 5, 3, 8, 12}, the maximum profit is 13 (buy at 1, sell at 5, buy at 3, sell at 12).

// Naive Solution: Recursive Approach
// Approach:
// - Consider all possible pairs of buy (i) and sell (j) days such that i < j.
// - For each such pair, calculate the profit by:
//   1. Selling on day j after buying on day i.
//   2. Recursively finding the maximum profit for days before i (left subarray).
//   3. Recursively finding the maximum profit for days after j (right subarray).
// - Return the maximum profit among all such cases.
// Time Complexity: O(2^n) (Exponential due to overlapping subproblems)
// Space Complexity: O(n) (Recursive stack)
int stockBuySellNaive(vector<int> &arr, int start, int end)
{
    int maxProfit = 0; // Initialize maxProfit to 0

    // Base case: If there's only one or no day, no profit can be made
    if (start >= end)
        return 0;

    // Loop through all possible buy days
    for (int i = start; i < end; i++)
    {
        // Loop through all possible sell days after the buy day
        for (int j = i + 1; j <= end; j++)
        {
            // If selling on day j yields profit, calculate it
            if (arr[j] > arr[i])
            {
                // Calculate the profit for buying on day i and selling on day j
                int currProfit = (arr[j] - arr[i]) + stockBuySellNaive(arr, start, i - 1) // Max profit from left subarray
                                 + stockBuySellNaive(arr, j + 1, end);                    // Max profit from right subarray

                // Update maxProfit if the current profit is higher
                maxProfit = max(maxProfit, currProfit);
            }
        }
    }

    return maxProfit; // Return the maximum profit found
}

// Efficient Solution: Greedy Approach
// Approach:
// - Traverse the array and add up all increases in stock price (arr[i] > arr[i-1]).
// - This effectively captures all possible profitable transactions.
// - Avoids unnecessary recursive calls and directly calculates the result in one pass.
// Time Complexity: O(n) (Single traversal of the array)
// Space Complexity: O(1) (No extra space used)
int stockBuySellEfficient(vector<int> &arr)
{
    int maxProfit = 0; // Initialize maxProfit to 0
    int n = arr.size();

    // Traverse the array from the second day
    for (int i = 1; i < n; i++)
    {
        // Add profit if the stock price increases from the previous day
        if (arr[i] > arr[i - 1])
        {
            maxProfit += (arr[i] - arr[i - 1]); // Add the difference to maxProfit
        }
    }

    return maxProfit; // Return the maximum profit
}

int main()
{
    // Example stock prices array
    vector<int> stocks{1, 5, 3, 8, 12};

    // Call the naive solution and print the result
    cout << "Naive Solution: " << stockBuySellNaive(stocks, 0, stocks.size() - 1) << endl;

    // Call the efficient solution and print the result
    cout << "Efficient Solution: " << stockBuySellEfficient(stocks) << endl;

    return 0;
}
