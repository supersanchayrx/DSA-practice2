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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        

        ListNode* dummy = new ListNode(0,head);
        ListNode* mover = dummy;
        ListNode* mover2 = dummy;

        while(mover->next!=NULL)
        {
            if(n)
                n--;
            else
                mover2= mover2->next;

            mover=mover->next;
        }

        ListNode* toDelete = mover2->next;
        mover2->next = mover2->next->next;
        delete toDelete;

        return dummy->next;
    }
};
