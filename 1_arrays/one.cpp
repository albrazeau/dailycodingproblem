// Get the product of all other elements

// Given an array of ints, return a new array such that each element at index i of the
// new array is the product of all the numbers in the original array except the one at i

// example input: [1, 2, 3, 4, 5]
// expected output: [120, 60, 40, 30, 24]

#include <iostream>
#include <vector>
using namespace std;

//
vector<int> prod(vector<int> arr)
{

    vector<int> results;

    // iterate over indexes of the vector
    for (int i = 0; i < arr.size(); i++)
    {
        // r will be used to create the products
        int r = 1;

        // iterate over the indexes again
        for (int j = 0; j < arr.size(); j++)
        {

            // only multiply r if the indexes are different
            if (i != j)
            {
                r *= arr[j];
            }
        }

        // collect the results
        results.push_back(r);
    }

    return results;
}

int main()
{
    // run the prod func
    vector<int> result = prod(vector<int>{1, 2, 3, 4, 5});

    // print the results
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "\n";
        }
    }

    return 0;
}
