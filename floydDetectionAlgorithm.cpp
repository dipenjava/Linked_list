#include "iostream"
using namespace std;
#include "map"
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
void insertAtTail(Node* &head,Node* &tail,int d)
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
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }

}
Node* flyodDetect(Node* &head)
{
    if(head==NULL)
        return NULL;
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }

    }
    return NULL;
}
Node* getStarting(Node* &head)
{
    if(head==NULL)
        return NULL;
    Node* intersection = flyodDetect(head);
    Node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(Node* &head)
{
    if(head==NULL)
        return;
    Node* start= getStarting(head);
    Node* temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;

    }
    temp->next=NULL;
}
void free(Node* &head)
{
    while(head!=NULL)
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
    }

}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    print(head);
    tail->next=head->next;
    if(flyodDetect(head)!=NULL)
    {
        cout<<"yes, loop is present"<<endl;
    }
    else
    {
        cout<<"No, loop is not present"<<endl;
    }
    Node* loop = getStarting(head);
    //print(head);
    cout<<"Loop begins at: "<<loop->data<<endl;
    removeLoop(head);
    print(head);
    free(head);


}







































//
// Created by 91919 on 07-08-2023.
//












//
// Created by 91919 on 07-08-2023.
//
