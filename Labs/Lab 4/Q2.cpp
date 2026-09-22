#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ab#c";
    string t = "ad#c";

    stack<char> st1;
    stack<char> st2;

    for (char c : s)
    {
        if (c == '#')
        {
            if (!st1.empty())
                st1.pop();
        }
        else
        {
            st1.push(c);
        }
    }

    for (char c : t)
    {
        if (c == '#')
        {
            if (!st2.empty())
                st2.pop();
        }
        else
        {
            st2.push(c);
        }
    }

    bool areEqual = true;

    if (st1.size() != st2.size())
    {
        areEqual = false;
    }
    else
    {
        while (!st1.empty())
        {
            if (st1.top() != st2.top())
            {
                areEqual = false;
                break;
            }

            st1.pop();
            st2.pop();
        }
    }

    cout << boolalpha << areEqual;

    return 0;
}