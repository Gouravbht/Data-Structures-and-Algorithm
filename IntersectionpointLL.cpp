#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

int getLength(ListNode* head) {
    int length = 0;
    ListNode* curr = head;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;

    // Align the pointers to the same starting point
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff > 0) {
            ptr1 = ptr1->next;
            diff--;
        }
    } else {
        int diff = len2 - len1;
        while (diff > 0) {
            ptr2 = ptr2->next;
            diff--;
        }
    }

    // Move both pointers until they meet or reach the end
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // No intersection found
    return NULL;
}

int main() {
    // Create two linked lists
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(6);
    head2->next = new ListNode(7);
    head2->next->next = head1->next->next;

    // Find the intersection point
    ListNode* intersectionNode = getIntersectionNode(head1, head2);

    // Print the intersection point or NULL
    if (intersectionNode != NULL)
        cout << "Intersection point: " << intersectionNode->val << endl;
    else
        cout << "No intersection point found." << endl;

    return 0;
}
