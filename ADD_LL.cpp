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


Node* reverse(Node* &head)
{
    Node* curr=head;
    Node* next=NULL;
    Node*prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    return prev;
}

Node* add(Node* &head1, Node* &head2)
{
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        int sum = carry + head1->data + head2->data;

        int digit= sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry= sum/10;
    }
    while(head1!=NULL)
    {
        int sum= carry + head1->data;
        int digit= sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry= sum/10;

    }
    while(head2!=NULL)
    {
        int sum= carry + head2->data;
        int digit= sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry= sum/10;

    }
    while (carry!=NULL)
    {
        int sum=carry;
        int digit= sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry= sum/10;
    }
    return ansHead;
}
Node* addtwoLL(Node* &head1, Node* &head2)
{
    head1= reverse(head1);
    head2= reverse(head2);
    Node* ans= add(head1,head2);
    ans=reverse(ans);
    return ans;

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
    insertAtTail(head1,tail1,4);
    insertAtTail(head1,tail1,5);
    print(head1);
    cout<<"Linked list 2:  ";
    insertAtTail(head2,tail2,7);
    insertAtTail(head2,tail2,0);
    insertAtTail(head2,tail2,4);
    insertAtTail(head2,tail2,9);
    insertAtTail(head2,tail2,1);
    print(head2);
    cout<<"reversed linked list 2 is: ";
    Node* karkedekho = reverse(head2);
    print(karkedekho);
   Node* doit = addtwoLL(head1,head2);
    print(doit);


}

































//
// Created by 91919 on 11-08-2023.
//


































//
// Created by 91919 on 20-08-2023.
//
