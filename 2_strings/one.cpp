// Finding anagram indices

// Given a word w and a string s, find all indices in s which are the
// starting locations of anagrams of w

// Example: w = "ab", s = "abxaba"
// Solution: [0, 3, 4]

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_anagram(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

vector<int> find_anagram_indices(string w, string s)
{
    int window_size = w.length();
    vector<int> results = vector<int>{};
    for (int i = 0; i < s.length(); i++)
    {
        if (is_anagram(w, s.substr(i, window_size)))
        {
            results.push_back(i);
        }
    }
    return results;
}

int main()
{
    string w = "ab";
    string s = "abxaba";
    vector<int> r = find_anagram_indices(w, s);
    for (auto &&n : r)
    {
        printf("%d ", n);
    }
    cout << "\n";
    return 0;
}