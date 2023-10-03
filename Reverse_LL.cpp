#include "iostream"
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &head,Node* &tail,int d)
{
    if(tail==NULL)
    {
        Node* newnode = new Node(d);
        tail=newnode;
        head=newnode;
    }
    else
    {
        Node* newnode= new Node(d);
        tail->next=newnode;
        tail=newnode;
    }
}
Node* reverse(Node* &head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* prev=NULL;
    Node* curr= head;
    Node* forward=NULL;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
void freeMemory(Node* &head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL; // Set the head to NULL to indicate the list is empty.
}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    print(head);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);

    cout<<"original linked list: "<<endl;

    print(head);
    head= reverse(head);
    cout<<"Reversed Linked list: "<<endl;
    print(head);
    freeMemory(head);



}

















//
// Created by 91919 on 02-08-2023.
//
