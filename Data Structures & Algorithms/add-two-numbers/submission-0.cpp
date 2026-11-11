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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // make a dummy nodes
        // start at both nodes
        // then reverse them add the end
        // can only return single digit node linked list
        // iterate through each listnode 
        // get the digit
        // convert to integers then add them
        // iterate again to get the linked list
        
        // dummy node
        ListNode* dummy = new ListNode();
        // pointer - point to head
        ListNode* current = dummy;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1;
            int v2;
            if (l1 != nullptr) {
                v1 = l1->val;
            } else {
                v1 = 0;
            }
            if (l2 != nullptr) {
                v2 = l2->val;
            } else {
                v2 = 0;
            }

            int val = v1 + v2 + carry;
            // if val is less than 10 -> val = 9 -> carry = 9 / 10 = 0.9 => 0
            // val is 30 -> carry = 30/10 = 3
            carry = val / 10;

            // val = 9 -> val = 9
            // val = 24 -> val = 4
            // we only want one digit
            val = val % 10;
            current->next = new ListNode(val);

            current = current->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            } else {
                l1 = nullptr;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            } else {
                l2 = nullptr;
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
