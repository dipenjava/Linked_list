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
void insertAtTail(Node*& head,Node* &tail,int d)
{
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp=new Node(d);
        tail->next=temp;
        tail=temp;

    }
}
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
Node* kReverse(Node* &head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    //step1: reverse first k nodes
    Node* next=NULL;
    Node* curr= head;
    Node* prev= NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        head->next= kReverse(next,k);
    }
    return prev;
}
void freeMemory(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* curr=temp;
        temp=temp->next;
        delete(curr);
    }
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,12);
    print(head);
    head= kReverse(head,3);
    cout<<"after k reverse LL is: "<<endl;
    print(head);
    freeMemory(head);


}



















//
// Created by 91919 on 03-08-2023.
//
