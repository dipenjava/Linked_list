#include "iostream"
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* &head)
{
    Node* temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void insertAtHead(Node* &tail,Node* &head,int d)
{

    if(head==NULL)
    {
        Node* temp= new Node(d);
        head=temp;
        tail=temp;

    }
    else
    {
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

    }
void insertAtTail(Node* & tail,Node* & head,int d)
{
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
        Node * temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }

}
void deleteNode(Node* &head,Node* &tail, int pos)
{

    if(pos==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;

    }
    else
    {

        Node* temp=head;
        Node* prev= NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=temp;
            temp=temp->next;
            cnt++;

        }
        if(temp->next==NULL)
        {
            tail=temp->prev;
        }
        temp->prev=NULL;
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}
void insertAtPos(Node* &tail,Node* &head,int pos, int d)
{
    if(pos==1)
    {
        insertAtHead(tail,head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }
    Node* newnode= new Node(d);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}
int main()
{

    Node* head=NULL;
    Node* tail=NULL;
    print(head);

    //cout<<"Length of DLL is: "<<getLength(head)<<endl;
    insertAtHead(tail,head,10);
    insertAtHead(tail,head,-8);
    print(head);
    insertAtTail(tail,head,11);
    insertAtTail(tail,head,99);
    print(head);
    insertAtPos(tail,head,2,100);
    print(head);
    insertAtPos(tail,head,1,33);
    print(head);
    cout<<"Length of DLL is: "<<getLength(head)<<endl;
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,5);
    deleteNode(head,tail,2);
    cout<<"Length of DLL is: "<<getLength(head)<<endl;
    print(head);
    cout<<"HEAD:  "<<head->data<<endl;
    cout<<"TAIL:  "<<tail->data<<endl;
    deleteNode(head,tail,2);
    print(head);
    cout<<"HEAD:  "<<head->data<<endl;
    cout<<"TAIL:  "<<tail->data<<endl;





}





























//
// Created by 91919 on 01-08-2023.
//
