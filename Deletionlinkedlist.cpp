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

void insertAthead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    } 
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node* head, int key) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAthead(node* &head) {
    if (head == NULL) {
        return;
    }
    node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deletion(node* &head, int val) {
    if (head == NULL) {
        return;
    }
    if (head->data == val) {
        deleteAthead(head);
        return;
    }
    node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return; // Value not found
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}




int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAthead(head, 4);
    display(head);
    cout << search(head, 6) << endl;
    deletion(head, 3);
    display(head);
    deleteAthead(head);
    display(head);
   
    return 0;
}
