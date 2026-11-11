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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        // min-heap approach

        // comparator for larger comparison for min-heap (default is less only)
        // also we're dealing with linked liss not integer
        // if integer we can just use (greater<int>)

        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);

        // build the min-heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                min_heap.push(list);
            }
        }

        // make the result linked list
        ListNode* result = new ListNode(0);
        // pointer
        ListNode* curr = result;

        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();
            // add the node to result linked list
            curr->next = node;
            // move to it
            curr = curr->next;

            node = node->next;
            if (node != nullptr) {
                // adjust the min-heap next
                min_heap.push(node);
            }
        }

        return result->next;
    }
};
