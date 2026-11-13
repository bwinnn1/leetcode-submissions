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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int group = 0;
        // iterate to the end of the first group
        while (curr != nullptr && group < k) {
            curr = curr->next;
            group++;
        }

        // found the group
        if (group == k) {
            curr = reverseKGroup(curr, k);
            // reverse each node of the group
            while (group-- > 0) {
                // basic reverse a linked list
                ListNode* tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
    }
};
