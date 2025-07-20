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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> myMap;

        for(int i=0; i<nums.size(); i++){
            myMap[nums[i]] = true;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        ListNode* current = head;

        while(current!=NULL){
            // we have to Delete it
            if(myMap[current->val] == true){
                prev->next = current->next;
            }
            else{
                // We Only move "prev" if the CURRENT Element is Not Deleted, Otherwise think about this case --> Deleted item: 1 & Linked List: 1 1 1 3
                // to Tackle this we do "else"
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};