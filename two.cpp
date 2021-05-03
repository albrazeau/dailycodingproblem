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

    void print()
    {
        printf("< Window  ||  start: %d  ||  stop: %d >\n", start, stop);
    }
};

Window findWindow(vector<int> arr)
{
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    int start;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != sorted[i])
        {
            start = i;
            break;
        }
    }

    int stop;
    for (int j = arr.size() - 1; j >= 0; j--)
    {
        if (arr[j] != sorted[j])
        {
            stop = j;
            break;
        }
    }

    return Window(start, stop);
}

int main()
{

    Window window = findWindow(vector<int>{3, 7, 5, 6, 9});
    window.print();

    return 0;
}