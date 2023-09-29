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
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
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
    Node* temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* solve(Node* &first,Node* &second)
{
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;
    while(next1!=NULL && curr2!=NULL)
    {
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data))
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
            
        }
        else
        {
            curr1=next1;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
Node* MergeList(Node* &head1, Node* &head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data<=head2->data)
    {
        return solve(head1,head2);
    }
    else
    {
        return solve(head2,head1);
    }

}
int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    Node* tail1=NULL;
    Node* tail2=NULL;
    cout<<"Linked List 1:  ";
    insertAtTail(head1,tail1,0);
    insertAtTail(head1,tail1,2);
    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,40);
    insertAtTail(head1,tail1,50);
    insertAtTail(head1,tail1,100);
    insertAtTail(head1,tail1,110);
    print(head1);
    cout<<"Linked list 2:  ";
    insertAtTail(head2,tail2,20);
    insertAtTail(head2,tail2,30);
    insertAtTail(head2,tail2,40);
    insertAtTail(head2,tail2,90);
    insertAtTail(head2,tail2,100);
    insertAtTail(head2,tail2,110);
    insertAtTail(head2,tail2,130);
    print(head2);
    MergeList(head1,head2);
    cout<<"Merge sorted LL is:  ";
    print(head1);


}

































//
// Created by 91919 on 11-08-2023.
//
