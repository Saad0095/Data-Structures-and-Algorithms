#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  3 pointer approach ; S.C => O(1) ; T.C => O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while(current != NULL){
            next = current -> next;
            current->next = prev;
            prev = current;
            current = next; 
        }
        return prev;
    }
};

int main(){
    
    return 0;
}