// Locate the smallest window to be sorted

// Given and array of ints that are out of order, determine the bounds of
// the smallest window that must be sorted in order for the entire array
// to be sorted.

// example: given [3, 7, 5, 6, 9]
// solution: (1, 3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Window
{
public:
    int start;
    int stop;

    Window(int _start, int _stop)
    {
        start = _start;
        stop = _stop;
    }

    Window(vector<int> _array)
    {
        vector<int> sorted = _array;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < _array.size(); i++)
        {
            if (_array[i] != sorted[i])
            {
                start = i;
                break;
            }
        }

        for (int j = _array.size() - 1; j >= 0; j--)
        {
            if (_array[j] != sorted[j])
            {
                stop = j;
                break;
            }
        }
    }

    void print()
    {
        printf("< Window  ||  start: %d  ||  stop: %d >\n", start, stop);
    }
};

int main()
{

    Window window(vector<int>{3, 7, 5, 6, 9});
    window.print();

    return 0;
}