#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string str) {
        string clean = "";

        for (char ch : str)
        {
            if (isalnum(ch))
            {
                clean += tolower(ch);
            }
        }

        stack<char> s;

        int mid = clean.size() / 2;

        for (int i = 0; i < mid; i++)
        {
            s.push(clean[i]);
        }

        int start = (clean.size() % 2 == 0) ? mid : mid + 1;

        for (int i = start; i < clean.size(); i++)
        {
            if (s.top() != clean[i])
                return false;

            s.pop();
        }

        return true;
    }
};

int main(){
    
    return 0;
}