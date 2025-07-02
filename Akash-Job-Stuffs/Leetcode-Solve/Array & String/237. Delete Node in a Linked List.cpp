/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Deleting Node here means just Deleting the "value" Not the Actual POINTER to the Node

        // 1. Copy the value of the next node to the current node.
        node->val = node->next->val;

        // 2. Pointing the next pointer to skip the next node... Thus, DELETING the NODE
        node->next = node->next->next;
    }
};