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


    return 0;
}
