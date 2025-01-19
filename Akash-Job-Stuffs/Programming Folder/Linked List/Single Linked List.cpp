#include<stdio.h>
//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *start=NULL;

void ListInsert(int num)
{
    //node *link=(node *)malloc(sizeof(node));
    node *link=new node();

    link->data=num;
    link->next=start;

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

/*void ReverseShowList()
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

}*/


void DeleteList(int num)
{
    node *current=start;
    node *previous=NULL;

    while(current!=NULL)
    {
        if( current->data == num)
        {
            if(previous==NULL)
            {
                start=current->next;
            }

            else
            {
                previous->next=current->next;
            }

        }

        previous=current;
        current=current->next;

    }

}


int Search(int num)
{
    node *current=start;

    if(current==NULL)
    {
        return 0;
    }

    while(current!=NULL)
    {
        if( current->data == num )
        {
            return 1;
        }

        current=current->next;
    }

    return 0;

}



int main()
{
    ListInsert(5);
    ListInsert(4);
    ListInsert(3);
    ListInsert(2);
    ListInsert(1);

    ShowList();

    DeleteList(3);

    if(Search(5)==1)
    {
        cout<<"Yes"<<endl;
    }

    ShowList();

    return 0;
}
