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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head; // Original LL

        ListNode* n1 = new ListNode(); // LL-1
        ListNode* n2 = new ListNode(); // LL-2

        ListNode* temp1 = n1; // iterate to LL-1
        ListNode* temp2 = n2; // iterate to LL-2

        while (temp != NULL) {
            if (temp->val < x) {
                temp1->next = temp;
                temp1 = temp1->next;
            } else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        // when we merge both the LL
        temp2->next = NULL; 
        temp1->next = n2->next; 

        return n1->next; 
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.partition(head, x);

    cout << "Partitioned List: ";
    printList(head);

    return 0;
}
