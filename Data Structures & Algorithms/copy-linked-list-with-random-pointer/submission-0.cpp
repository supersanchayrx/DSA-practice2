/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> nodeMap; 
        Node* tempHead = head;


        while(tempHead!=NULL)
        {
            Node* copiedNode = new Node(tempHead->val);
            nodeMap[tempHead] = copiedNode;

            tempHead = tempHead->next;
        }

        tempHead = head;

        while(tempHead!=NULL)
        {
            nodeMap[tempHead]->next = nodeMap[tempHead->next];
            nodeMap[tempHead]->random = nodeMap[tempHead->random];
            tempHead = tempHead->next;
        }

        return nodeMap[head];
    }
};
