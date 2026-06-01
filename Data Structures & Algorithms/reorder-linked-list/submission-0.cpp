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
    void reorderList(ListNode* head) 
    {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;

        while(fastPtr!=NULL && slowPtr!=NULL && fastPtr->next!=NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = slowPtr->next;
        slowPtr->next = nullptr;

        // if(halfEnd->next != slowPtr)
        //     return;

        ListNode* tempMover = h2;

        ListNode* prev = nullptr;
        
        while(tempMover!=NULL)
        {
            ListNode* tempNext = tempMover->next;
            tempMover->next = prev;
            prev = tempMover;
            tempMover = tempNext;
        }
        
        h2 = prev;

        while(h1!=NULL && h2!=NULL)
        {
            ListNode* tempNextH1 = h1->next;
            ListNode* tempNextH2 = h2->next;

            h1->next = h2;
            h1 = h2->next = tempNextH1;
            h2 = tempNextH2;
            //h1 = tempNextH1;
        }

    }
};
