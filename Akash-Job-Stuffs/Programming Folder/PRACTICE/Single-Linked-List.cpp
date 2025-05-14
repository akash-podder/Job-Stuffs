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

ListNode* DeleteNode(ListNode* head, int value){
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* temp = dummy;
    ListNode* current = head;

    while(current!=NULL){
        if(current->val == value){
            temp->next = current->next;
            break;
        }

        current = current->next;
        temp = temp->next;
    }

    return dummy->next;
}

void Print(ListNode* head){
	ListNode* current = head;
    cout<<"Linked List: ";
    
	while(current!=NULL){
	    cout<<current->val<<" ";
	    current = current->next;
    }

    cout<<endl;
}

int main(){
	ListNode* head  = AddNode(NULL, 4);
	head  = AddNode(head, 2);
	head  = AddNode(head, 1);
	Print(head);
	head  = DeleteNode(head, 2);
	Print(head);
	
    return 0;
}