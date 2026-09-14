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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        bool isPalindrome = true;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow-> next;
        slow-> next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = l2;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }

        while(head != NULL && prev != NULL){
            if(head -> val != prev -> val){
                isPalindrome = false;
                break;
            }
            head = head->next;
            prev = prev->next;
        }
        return isPalindrome;
    }
};