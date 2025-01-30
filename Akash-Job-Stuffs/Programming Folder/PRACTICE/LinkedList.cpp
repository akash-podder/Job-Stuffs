#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int

#define goat                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

class Node {
    public:
        int val;
        Node* next;
        Node(int value){
            val = value;
            next = NULL;
        }

};

void PrintLinkedList(Node* &head){

    Node* current = head;
    while (current!= NULL)
    {
        cout<<current->val;
        if(current->next!=NULL){
            cout<<"--->";
        }else{
            cout<<endl;
        }
        current = current->next;
    }
}

void InsertNodeAtTail(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next!=NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main()
{
    goat;

    Node* head = NULL;

    InsertNodeAtTail(head, 2);
    InsertNodeAtTail(head, 3);
    InsertNodeAtTail(head, 4);
    
    PrintLinkedList(head);
    
    return 0;
}