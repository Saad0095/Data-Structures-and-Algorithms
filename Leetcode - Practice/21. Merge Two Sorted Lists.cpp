1. Iterative Approach (Recommended)This approach uses a dummy node to simplify the head pointer management. We use a tail pointer to track the end of our newly merged list, traversing both lists and choosing the smaller node at each step

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the anchor for the new list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Traverse both lists until one runs out
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining elements of the non-empty list
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        // Return the actual head of the merged list
        return dummy.next;
    }
};


The recursive solution checks the base cases first. If either list is empty, it returns the other list. Otherwise, it compares the values, links the smaller node, and recurses on the rest. [1] (https://algo.monster/liteproblems/21), [2] (https://www.youtube.com/watch?v=V5kl3nc3ed4), [3] (https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/21.%20Merge%20Two%20Sorted%20Lists.cpp)

    class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases: if one list is empty, return the other list
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        // Choose the smaller node and recursively merge the rest
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
