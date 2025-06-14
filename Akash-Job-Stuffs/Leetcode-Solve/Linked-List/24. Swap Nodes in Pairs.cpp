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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* prev = dummy;
        ListNode* current = head;

        while(current!=NULL){
            
            if(current->next==NULL){
                break;
            }

            ListNode* nextNode = current->next;
            ListNode* nextTwoStep = current->next->next; // this is to "ITERATE" for the Next Pair
            
            // we are Swapping TWO Nodes here
            nextNode->next = current;
            current->next = nextTwoStep;
            prev->next = nextNode;

            prev = current;
            current = nextTwoStep; // ITERATING to the Next Pair
        }

        return dummy->next;
    }
};