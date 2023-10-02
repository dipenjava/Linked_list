#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d) {
    if (tail == NULL) {
        Node* newnode = new Node(d);
        tail = newnode;
        head = newnode;
    } else {
        Node* newnode = new Node(d);
        tail->next = newnode;
        tail = newnode;
    }
}

Node* getMid(Node* &head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverse(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    Node* middle = getMid(head);
    Node* secondHalf = reverse(middle->next);

    Node* head1 = head;
    Node* head2 = secondHalf;

    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    middle->next = reverse(secondHalf);
    return true;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 10);

    print(head);
    Node* temp = getMid(head);
    cout << "Mid element is: " << temp->data << endl;

    if (isPalindrome(head)) {
        cout << "Yes, it is palindrome" << endl;
    } else {
        cout << "No, it is not palindrome" << endl;
    }

    return 0;
}
