
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nextTemp = head->next;
        head->next = prev;
        prev = head;
        head = nextTemp;
    }
    return prev;
}


ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);


    ListNode* reversedIterative = reverseListIterative(head);
    cout << "Reversed List (Iterative): ";
    printList(reversedIterative);


    ListNode* reversedRecursive = reverseListRecursive(reversedIterative);
    cout << "Reversed List (Recursive): ";
    printList(reversedRecursive);

    return 0;
}
