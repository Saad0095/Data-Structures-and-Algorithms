#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *prev;

    Node(string val = " ")
    {
        url = val;
        next = prev = NULL;
    }
};

class BrowserHistory
{
private:
    Node *curr;

public:
    BrowserHistory(string homepage)
    {
        curr = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);

        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    string forward(int steps)
    {
        // Node* temp = curr;
        for (int i = 0; i < steps; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
            else
            {
                break;
            }
        }
        return curr->url;
    }
    string back(int steps)
    {
        // Node* temp = curr;
        for (int i = 0; i < steps; i++)
        {
            if (curr->prev != NULL)
            {
                curr = curr->prev;
            }
            else
            {
                break;
            }
        }
        return curr->url;
    }
};

int main()
{
    BrowserHistory browserHistory("leetcode.com");

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");

    cout << browserHistory.back(1) << endl;
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.forward(1) << endl;

    browserHistory.visit("linkedin.com");

    cout << browserHistory.forward(2) << endl;
    cout << browserHistory.back(2) << endl;
    cout << browserHistory.back(7) << endl;

    return 0;
}