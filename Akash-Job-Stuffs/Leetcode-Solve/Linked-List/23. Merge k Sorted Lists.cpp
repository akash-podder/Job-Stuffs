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
ListNode* mergeTwoList(ListNode* root1, ListNode* root2){

    ListNode* i1 = root1;
    ListNode* i2 = root2;

    // this will be the Head of our "NEW Node"
    ListNode* newNode = new ListNode();
    ListNode* newRoot = newNode;

    while(i1!=NULL && i2!=NULL){
        if(i1->val <= i2->val){
            newNode->next = i1;
            i1 = i1->next;
            newNode = newNode->next;
        }
        else{
            newNode->next = i2;
            i2 = i2->next;
            newNode = newNode->next;
        }
    }

    // we iterate over Remaining "List 1" elements and append to our New List
    while(i1!=NULL){
        newNode->next = i1;
        i1 = i1->next;
        newNode = newNode->next;
    }


    // we iterate over Remaining "List 2" elements and append to our New List
    while(i2!=NULL){
        newNode->next = i2;
        i2 = i2->next;
        newNode = newNode->next;
    }

    return newRoot->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* newRoot = NULL;

    // if List is Equal to 1 element, then we Return that element's Head
    if(lists.size()==1){
        newRoot = lists[0];
    }

    // if more than Equal to 2 elements, then we merge the elements
    else if(lists.size()>=2){
        newRoot = mergeTwoList(lists[0], lists[1]);

        for(int i=2; i<lists.size(); i++){
            newRoot = mergeTwoList(newRoot, lists[i]);
        }
    }

    return newRoot;
}
};