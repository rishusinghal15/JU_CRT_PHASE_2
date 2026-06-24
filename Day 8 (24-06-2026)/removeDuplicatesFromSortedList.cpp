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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr!= NULL && curr->next != NULL)
        {
            if(curr->val == curr->next->val)
            {
                ListNode* backup = curr->next->next; 
                delete curr->next; 
                curr->next = backup; 
            }
            else 
            {
                curr = curr->next; 
            }
        }
        return head; 
    }
};

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution obj;
    head = obj.deleteDuplicates(head);

    printList(head);

    return 0;
}