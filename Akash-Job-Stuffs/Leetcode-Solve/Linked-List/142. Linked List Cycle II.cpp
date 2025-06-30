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
    ListNode *getIntersectionNode(ListNode *p1, ListNode *p2){
        
        // This we move Both the Points by 1 Step... Nobody will be fast & slow
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL && fast!=NULL){
            if(fast->next!=NULL){
                fast = fast->next->next;
            }
            else{
                return NULL;
            }

            slow = slow->next;

            if(slow!=NULL && fast!=NULL && slow==fast){
                // Detecting the "intersection" Point
                ListNode* start=head;
                return getIntersectionNode(slow, start);
            }
        }

        return NULL;
    }
};