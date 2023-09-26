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
bool detectLoop(Node* &head)
{
    if(head==NULL)
    {
        return false;
    }

    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL) {
        if (visited[temp]) {
            cout << "present at element: " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;

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
    if(detectLoop(head))
    {
        cout<<"yes, loop is present"<<endl;
    }
    else
    {
        cout<<"No, loop is not present"<<endl;
    }


}







































//
// Created by 91919 on 07-08-2023.
//
