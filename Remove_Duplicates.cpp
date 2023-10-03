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
Node* removeD(Node* head)
{
    if(head==NULL)
        return NULL;
    Node* curr=head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) && (curr->data==curr->next->data))
        {
            Node* next_next=curr->next->next;
            Node* nodeToDelete= curr->next;
            delete(nodeToDelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    print(head);
    head = removeD(head);
    print(head);






}





















//
// Created by 91919 on 08-08-2023.
//
