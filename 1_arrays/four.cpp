// Find number of smaller elements to the right

// Given an array of intergers, return a new array where each element
// in the new array is the number of smaller elements to the right
// of that element in the original input array

// Example: [3, 4, 9, 6, 1]
// Solution [1, 1, 2, 1, 0]

#include <iostream>
#include <vector>
using namespace std;

vector<int> num_smaller(vector<int> arr)
{
    vector<int> results = vector<int>{};

    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i];

        int result = 0;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < val)
            {
                result++;
            }
        }
        results.push_back(result);
    }

    return results;
}

int main()
{
    vector<int> r = num_smaller(vector<int>{3, 4, 9, 6, 1});

    for (auto &&n : r)
    {
        printf("%d ", n);
    }
    cout << "\n";

    return 0;
}