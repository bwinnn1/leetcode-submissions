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
        // have a result linked list

        // iterate 

        // [1, 2, 3] [3, 5, 6]

        // make a new dummy node for the merged linked list
        ListNode dummy(0);
        
        // pointer to point to the end of the dummy node
        ListNode* tail = &dummy;

        // while both list have numbers
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                // insert list1 to the merged list
                tail->next = list1;
                // move to the next node
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            // move the tail to the new node that we just inserted
            tail = tail->next;
        }
        
        // when one list becomes empty or reaches the end. Insert the remaining of the other list to the merged list
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};
