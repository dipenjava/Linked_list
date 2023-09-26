#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* random;
    Node(int data)
    {
        this->data =data;
        this->next = NULL;
        this->random = NULL;
    }
};
void insertAtTail(Node* &head, Node* &tail , int data)
{
    Node* newnode = new Node(data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}
void printLL(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head= NULL;
    Node* tail=NULL;
    insertAtTail(head, tail,10);
    insertAtTail(head, tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    cout<<"Linked list is: ";
    printLL(head);
}













































//
// Created by 91919 on 16-09-2023.
//
