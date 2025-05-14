#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(){};

	ListNode(int x){
        val = x;
    };
};

ListNode* AddNode(ListNode* head, int val){
	ListNode* newNode = new ListNode(val);
	
    if(head==NULL) {
        head = newNode;
    }
    else{
        ListNode* current = head;
        while(current->next!=NULL){
            current = current->next;
        }

        current->next = newNode;
    }
    
    return head;
}

void Print(ListNode* head){
	ListNode* current = head;
	while(current!=NULL){
	    cout<<current->val<<endl;
	    current = current->next;
    }
}

int main(){
	ListNode* head  = AddNode(NULL, 4);
	head  = AddNode(head, 2);
	head  = AddNode(head, 1);
	Print(head);
	return 0;
}