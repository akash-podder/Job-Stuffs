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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* current = head;
        ListNode* prev = dummy;

        while(current!=NULL){
            if(current->val==val){
                prev->next = current->next;
            }

            // Test Case: head = [7,7,7,7] ... Output: []
            else{
                prev = current;
            }

            current = current->next;
        }

        return dummy->next;
    }
};