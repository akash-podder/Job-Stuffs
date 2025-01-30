#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};


node *start=NULL;
node *finish=NULL;


bool isEmpty()
{
    if(start==NULL)
    {
        return true;
    }

    return false;
}


void ListInsert(int num)
{
    node *link=(node *)malloc(sizeof(node));

    link->data=num;
    link->next=start;
    link->prev=NULL;

    if(isEmpty())
    {
        finish=link;
    }

    else
    {
        start->prev=link;
    }

    start=link;
}


void ShowList()
{
    node *current=start;

    //cout<<"List Items:"<<endl;
    printf("List Items:");

    while(current!=NULL)
    {
        //cout<< current->data;
        printf("%d ", current->data);
        current=current->next;
    }

    printf("\n");

}


void ShowReversedList()
{
    node *current=finish;

    printf("List Items:");

    while(current!=NULL)
    {
        printf("%d ", current->data);
        current=current->prev;
    }

    printf("\n");

}


int main()
{
    ListInsert(5);
    ListInsert(4);
    ListInsert(3);
    ListInsert(2);
    ListInsert(1);

    ShowList();

    ShowReversedList();

    return 0;
}
