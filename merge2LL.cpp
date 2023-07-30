 #include <iostream>
using namespace std;

// Node class to represent a node in the linked list
class Node {
public:
    int data;
    Node* next;
};

// Function to merge two sorted linked lists
Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    
    Node* mergedHead = NULL;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeLists(head1, head2->next);
    }
    
    return mergedHead;
}

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    // Create the first linked list
    insert(&head1, 1);
    insert(&head1, 3);
    insert(&head1, 5);
    
    // Create the second linked list
    insert(&head2, 2);
    insert(&head2, 4);
    insert(&head2, 6);
    
    cout << "First linked list: ";
    display(head1);
    
    cout << "Second linked list: ";
    display(head2);
    
    Node* mergedList = mergeLists(head1, head2);
    cout << "Merged linked list: ";
    display(mergedList);
    
    return 0;
}
