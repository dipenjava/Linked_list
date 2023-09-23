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
void insertAtTail(Node* &head, Node* &tail,int d)
{
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp= new Node(d);
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
Node* sortedLL(Node* &head)
{
    int zero=0;
    int one=0;
    int two=2;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero++;
        }
        else if(temp->data==1)
        {
            one++;
        }
        else if(temp->data==2)
        {
            two++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(zero!=0)
        {
            temp->data=0;
            zero--;
        }
        else if(one!=0)
        {
            temp->data=1;
            one--;
        }
        else if(two!=0)
        {
            temp->data=2;
            two--;
        }
        temp=temp->next;
    }
    return head;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    cout<< "Linked List is: ";
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    print(head);
    head = sortedLL(head);
    cout<<"Sorted LL is: ";
    print(head);

}






















//
// Created by 91919 on 09-08-2023.
//
