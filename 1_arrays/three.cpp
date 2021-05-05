// Calculate the maximum subarray sum

// Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
// Do this in O(n) tume.

// Example: [34, -50, 42, 14, -5, 86]
// Solution: 137, because 42 + 14 + -5 + 86

#include <iostream>
#include <vector>
using namespace std;

int maximum_subarray_brute_force(vector<int> arr)
{

    int max_sum = 0;
    for (int start = 0; start < arr.size() - 1; start++)
    {

        for (int stop = arr.size() - 1; stop >= 0; stop--)
        {

            if (start < stop)
            {

                int sum = 0;
                for (int i = start; i <= stop; i++)
                {
                    sum += arr[i];
                }

                if (sum > max_sum)
                {
                    max_sum = sum;
                }
            }
        }
    }

    return max_sum;
}

int maximum_subarray_kadane(vector<int> arr)
{
    int max_ending_here = 0;
    int max_so_far = 0;

    for (auto &&val : arr)
    {
        max_ending_here = max(val, max_ending_here + val);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int result1 = maximum_subarray_brute_force(vector<int>{34, -50, 42, 14, -5, 86});
    printf("Maximum sum of contiguous subarray brute force: %d\n", result1);

    int result2 = maximum_subarray_kadane(vector<int>{34, -50, 42, 14, -5, 86});
    printf("Maximum sum of contiguous subarray Kadane's Algorithm: %d\n", result2);

    return 0;
}