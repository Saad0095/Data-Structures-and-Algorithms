// A palindrome is a word, phrase, number, or another sequence of characters that reads the same
// backward and forwards. Can you determine if a given string, s, is a palindrome? Write a Program
// using stack for checking whether a string is palindrome or not.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(string string)
    {
        stack<char> s;
        int mid = string.size() / 2;
        for (int i = 0; i < mid; i++)
        {
            s.push(string[i]);
        }
        
        int start = (string.size() % 2 == 0) ? mid : mid + 1;
        for (int i = start; i <= string.size() - 1; i++)
        {
            if (s.top() != string[i])
                return -1;
            s.pop();
        }
        return 1;
    }
};

int main()
{
    Solution s;

    cout << "abba: "<<s.isValid("abba") << "\n";
    cout << "abab: "<<s.isValid("abab") << "\n";
    return 0;
}