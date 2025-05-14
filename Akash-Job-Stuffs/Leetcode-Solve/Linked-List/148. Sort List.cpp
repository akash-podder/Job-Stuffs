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
    //  this is For Merging Two SORTED ListNode
    ListNode* mergeTwoSortedList(ListNode* root1, ListNode* root2){
        ListNode* newRoot = new ListNode(0);
        ListNode* nextNode = newRoot;

        ListNode* current1 = root1;
        ListNode* current2 = root2;

        while(current1!=NULL && current2!=NULL){
            if(current1->val <= current2->val){
                nextNode->next = current1;
                nextNode = nextNode->next;
                current1=current1->next;
            }
            else{
                nextNode->next = current2;
                nextNode = nextNode->next;
                current2=current2->next;
            }
        }

        while(current1!=NULL){
            nextNode->next = current1;
            nextNode = nextNode->next;
            current1=current1->next;
        }

        while(current2!=NULL){
            nextNode->next = current2;
            nextNode = nextNode->next;
            current2=current2->next;
        }

        return newRoot->next;
    }

    ListNode* mergeSortAlgo(ListNode* head){
        // Base case:
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        while(slow!=NULL && fast!=NULL){
            if(fast!=NULL){
                fast = fast->next;

                if(fast!=NULL){
                    fast = fast->next;
                }
                else{
                    break;
                }
            }
            
            if(slow!=NULL){
                prev = slow;
                slow = slow->next;
            }
        }

        if(prev!=NULL){
            prev->next = NULL;
        }

        ListNode* leftSide = mergeSortAlgo(head);
        ListNode* rightSide = mergeSortAlgo(slow);

        return mergeTwoSortedList(leftSide, rightSide);
    }

    ListNode* sortList(ListNode* head) {

        return mergeSortAlgo(head);
    }
};