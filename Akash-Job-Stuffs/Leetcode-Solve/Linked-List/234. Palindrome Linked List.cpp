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
    pair<ListNode*, int> getMiddleNode(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        int len=0;

        while(fast!=NULL && slow!=NULL){
            if(fast!=NULL){
                len++;
                if(fast->next!=NULL){
                    fast = fast->next->next;
                    len++;
                }
                else{
                    break;
                }
            }
            if(slow!=NULL){
                slow = slow->next;
            }
        }

        return make_pair(slow,len);
    }

    ListNode* reverseUpToMiddleNode(ListNode* head, ListNode* middle){
        ListNode* prev = NULL;
        ListNode* current = head;

        while(current!=middle){
            ListNode* tempNextNode = current->next;
            current->next = prev;
            prev = current;
            current = tempNextNode;    
        }

        return prev;
    }
    
    bool checkTwoListPalindrome(ListNode* head, ListNode* middle){
        ListNode* current1 = head;
        ListNode* current2 = middle;

        while(current1!=NULL && current2!=NULL){
            if(current1->val!=current2->val){
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        // Steps:

        // 1. get middle Node & the "Length" of the Linked List
        pair<ListNode*, int> pair = getMiddleNode(head);
        ListNode* middle = pair.first;
        int len = pair.second;

        // 2. Reverse from Head to "Before" the Middle Node
        head = reverseUpToMiddleNode(head, middle);

        // 3. if "ODD" Length we SKIP the Middle Node to NEXT Node
        if(len%2==1) if(middle!=NULL) middle = middle->next;

        // 4. we Simply Compare the TWO Linked Lists if they contains EQUAL VALUES
        return checkTwoListPalindrome(head, middle);
    }
};