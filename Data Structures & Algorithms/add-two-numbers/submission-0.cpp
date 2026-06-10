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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* tempHead1 = l1;
        ListNode* tempHead2 = l2;

        ListNode* head = new ListNode();
        ListNode* tempHead = head;
        int carry = 0;

        while(tempHead1!=NULL || tempHead2!=NULL || carry)
        {
            int a = tempHead1 != NULL ? tempHead1->val: 0 ;
            int b = tempHead2 != NULL ? tempHead2->val : 0 ;

            int c = a+b+carry;

            carry = c/10;

            tempHead->val = c%10;

            if((tempHead1!=NULL && tempHead1->next!=NULL) || (tempHead2!=NULL && tempHead2->next!=NULL) || carry)
            {
                ListNode* newNode = new ListNode();
                tempHead->next = newNode;
            }

            if(tempHead->next!=nullptr)
                tempHead=tempHead->next;

            if(tempHead1)
                tempHead1=tempHead1->next;
            if(tempHead2)
                tempHead2=tempHead2->next;
        }

        return head;
    }
};
