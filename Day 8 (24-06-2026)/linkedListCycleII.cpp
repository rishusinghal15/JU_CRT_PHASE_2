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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool flag = false;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                flag = true;
                break;
            }
        }

        if (flag == false) {
            return NULL;
        } else {
            slow = head;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};

int main() {

    // Create list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: -4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;

    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle starts at node with value: "
             << cycleStart->val << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}