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
    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};
void insert(Node*& tail,int element,int d)
{
    if(tail==NULL)
    {
        Node* newnode= new Node(d);
        tail=newnode;
        newnode->next=newnode;

    }
    else
    {
        Node* curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        Node* temp= new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node * tail)
{
    Node* temp=tail;
    if(tail==NULL)
    {
        cout<<"bhaisahab list is empty";
        return ;
    }
    do{
        cout<<tail->data<<"  ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;

}
void deleteNode(Node* &tail,int value)
{
    if(tail==NULL)
    {
        cout<<"Link is empty brother";

    }
    else
    {
        Node* prev=tail;
        Node* curr=tail->next;
        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr==prev)
        {
            tail=NULL;
        }
        else if(tail==curr)
        {
            tail=prev;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* tail= NULL;
    insert(tail,6,9);
    print(tail);
    insert(tail,9,11);
    print(tail);
    insert(tail,11,13);
    insert(tail,11,12);
    insert(tail,13,17);
    insert(tail,17,22);
    print(tail);
    deleteNode(tail,22);
    print(tail);
    deleteNode(tail,12);
    print(tail);
    deleteNode(tail,9);
    print(tail);
    deleteNode(tail,17);
    print(tail);
    deleteNode(tail,13);
    print(tail);
    deleteNode(tail,11);
    print(tail);







}











































//
// Created by 91919 on 01-08-2023.
//
