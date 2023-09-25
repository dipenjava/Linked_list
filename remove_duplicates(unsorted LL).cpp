#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << std::endl;
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
void bubbleSort(Node* head) {
    if (head==NULL || head->next==NULL)
        return;

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    insert(head, 5);
    insert(head, 2);
    insert(head, 8);
    insert(head, 2); // Adding an equal element
    insert(head, 3);

    cout << "Original List: ";
    printList(head);

    bubbleSort(head);

    cout << "Sorted List: ";
    printList(head);
    head= removeD(head);
    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}














//
// Created by 91919 on 09-08-2023.
//
