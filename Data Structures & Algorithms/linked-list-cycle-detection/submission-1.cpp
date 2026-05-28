/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;

        while(fastPtr!=NULL && slowPtr!=NULL && fastPtr->next!=NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(fastPtr == slowPtr)
                return true;
            
        }

        return false;
    }
};
