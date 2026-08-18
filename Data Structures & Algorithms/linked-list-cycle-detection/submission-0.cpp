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
    bool hasCycle(ListNode* head) {
        // hash table to keep track of visited node

        // if index is not given how do we know if there is a cycle?

        // iterate?

        // one node in the list can be visited again by following the next pointer
        
        // two pointers - one slow , one fast

        // both start at head
        ListNode* slow = head;
        ListNode* fast = head;
        
        // as long as it's not the end
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
