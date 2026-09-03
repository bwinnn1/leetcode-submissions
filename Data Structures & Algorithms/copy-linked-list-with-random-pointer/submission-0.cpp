/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
if (head == nullptr) return nullptr;

        // Maps: original node -> its new copy.
        // This is the table you just saw.
        unordered_map<Node*, Node*> oldToNew;

        // Pass 1: create every new node FIRST, before wiring any pointers.
        // Doing this in its own pass guarantees that by the time Pass 2
        // needs to link to some node's copy, that copy already exists,
        // no matter where in the list it is.
        Node* curr = head;
        while (curr != nullptr) {
            // hash map of current pointer = current pointer's node's value
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: now every copy exists, so just look up the right ones.
        curr = head;
        while (curr != nullptr) {
            oldToNew[curr]->next = curr->next ? oldToNew[curr->next] : nullptr;
            oldToNew[curr]->random = curr->random ? oldToNew[curr->random] : nullptr;
            curr = curr->next;
        }

        return oldToNew[head];
    }
};
