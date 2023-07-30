#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}



void display(node* head) {
    node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void evenAfterOdd(node* &head) {
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while (odd->next != head && even->next != head) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

    if (even != NULL) {
        even->next = NULL;
    }
}

int main() {
    node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        insertAtTail(head, arr[i]);
    }
    cout << "Original list: ";
    display(head);

    evenAfterOdd(head);
    cout << "List after rearranging odd and even nodes: ";
    display(head);

    return 0;
}
