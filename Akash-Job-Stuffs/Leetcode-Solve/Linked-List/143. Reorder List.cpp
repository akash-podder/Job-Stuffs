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
    ListNode* reverseList(ListNode* head){
        ListNode* current = head;
        ListNode* newNodeHead = NULL;
        
        while(current!=NULL){
            ListNode* NextNode = current->next;
            current->next = newNodeHead;
            newNodeHead=current;
            current=NextNode;
        }

        // Return the "newNodeHead"
        return newNodeHead;
    }

    void mergeTwoList(ListNode* head1, ListNode* head2){
        ListNode* current1 = head1;
        ListNode* current2 = head2;

        while(current1!=NULL && current2!=NULL){
            ListNode* nextNode1 = current1->next;
            ListNode* nextNode2 = current2->next;

            current1->next = current2;
            current2->next = nextNode1;

            current1=nextNode1;
            current2=nextNode2;
        }
    }

    void reorderList(ListNode* head) {
        // 1. Find the middle by moving fast & slow iterators.
        // 2. Remember right part beginning and cut off left part from the right.
        // 3. Reverse right list, remember it new beginning.
        // 4. Iterate left part from beginning and right part merging right list nodes into left list.

        // reverseList(head);

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && slow!=NULL){

            // Fast Pointer Moves by Two Steps
            if(fast!=NULL){
                fast = fast->next;
                if(fast!=NULL){
                    fast = fast->next;
                }
            }

            // this is to Get Middle Node if ODD & Last Node Before Middle Node if Even
            if(fast==NULL){
                break;
            }

            // Slow Pointer Moves by One Steps
            if(slow!=NULL) {
                slow = slow->next;
            }
        }

        // Slow Pointer's NEXT is the Second Linked List's NEW Head
        ListNode* newHead = slow->next;
        // we are Dividing the LinkedList into 2 LinkedList
        slow->next=NULL;

        // Reversing the New Linked List comprising of the 2nd Half of the Original
        newHead = reverseList(newHead);

        // Merging the Two Lists Together to form the Answer
        mergeTwoList(head, newHead);
    }
};