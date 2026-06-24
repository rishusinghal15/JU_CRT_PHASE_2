#include<iostream>
using namespace std; 

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; 
        node->next = node->next->next;  
    }
};

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    Solution obj;

    // Delete node with value 5
    obj.deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}