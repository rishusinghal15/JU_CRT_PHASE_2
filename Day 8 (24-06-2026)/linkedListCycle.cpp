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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head; 
        ListNode* slow = head; 

        while(fast!= NULL && fast->next != NULL)
        {
            fast = fast->next->next; 
            slow = slow->next; 

            if(fast == slow)
            return true; // cycle found
        }
        // no cycle found 
        return false; 
    }
};

int main()
{
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: -4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;

    if(obj.hasCycle(head))
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle Found" << endl;

    return 0;
}
