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
void insertAtTail(Node* &head,Node* &tail,int d)
{
    if(tail==NULL)
    {
        Node* temp= new Node(d);
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
    //int cnt=1;
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
        //cnt++;
    }
    cout<<endl;

}
int getLength(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {

        temp=temp->next;
        len++;
    }
    return len;
}
Node* findmiddle(Node * head)
{
    if (head == NULL)
        return NULL;

    int len = getLength(head);
    int middleIndex = (len / 2) + 1 ; // Adding 1 to handle 1-based index
    Node* temp = head;
    int cnt = 1;

    while (cnt < middleIndex)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
}
void deleteNode(Node* &head)
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
        Node* head = NULL;
        Node* tail = NULL;
        insertAtTail(head, tail, 1);
        print(head);
        insertAtTail(head, tail, 3);
        insertAtTail(head, tail, 5);
        insertAtTail(head, tail, 7);
        //insertAtTail(head, tail, 11);

        print(head);
        cout << "Length of LL is: " << getLength(head) << endl;

        Node* middleNode = findmiddle(head);
        if (middleNode)
        {
            cout << "Middle element is: " << middleNode->data << endl;
        }
        else
        {
            cout << "The list is empty. Cannot find the middle element." << endl;
        }
    deleteNode(head);

        return 0;


}




































//
// Created by 91919 on 02-08-2023.
//
