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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2 4 8 6 . slow is at 4 when fast->next == nullptr so secondHalf = slow->next
        ListNode* secondHalf = slow->next;
        // cut off
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        while (curr != nullptr) {
            ListNode* next = curr->next; // save
            curr->next = prev; // point backward
            prev = curr; // advance prev to curr
            curr = next; // advance curr to curr -> next
        }
        secondHalf = prev; // make secondHalf becomes prev since prev is flipped

        // merge them together 
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext; // advance first to its next
            second = secondNext; // advance second to its next
        }
    }
};
