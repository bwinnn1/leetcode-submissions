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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // constraints : cannot get the length
        // 1 2 3 4 n = 2 -> remove 3 
        // reverse the list
        // everytime we advance decrease n by 1.
        // and when n == 0. remove that node. then reverse the list back

        // edge case :
        // if head->next == nullptr and n == 1
        // remove head return empty

        if (head->next == nullptr && n == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // set current Reverse to prev which is pointing in reverse
        ListNode* currRev = prev;
        // before target to keep track of it
        ListNode* beforeTarget = nullptr;
        ListNode* target = currRev;
        // loop
        for (int i = 0; i < n - 1; i++) {
            // keep track of before target and target at its location
            beforeTarget = target;
            target = target->next;
        }

        if (beforeTarget == nullptr) {
            currRev = target->next;
        } else {
            beforeTarget->next = target->next;
        }
        delete target;
        // TODO: reserve back to the original

        ListNode* secondRev = currRev;
        ListNode* prev2 = nullptr;

        while (secondRev != nullptr) {
            ListNode* temp = secondRev->next;
            secondRev->next = prev2;
            prev2 = secondRev;
            secondRev = temp;
        }

        return prev2;
    }
};
