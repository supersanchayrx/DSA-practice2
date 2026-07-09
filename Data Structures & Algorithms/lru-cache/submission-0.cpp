class LRUCache {

private:
    struct Node{
        int val = 0;
        int key = -1;
        Node* next = nullptr;
        Node* prev = nullptr;

        public:
            Node(int value)
            {
                val = value;
                next = nullptr;
                prev = nullptr;
            }

            Node(int value, int keyValue)
            {
                val = value;
                key = keyValue;
                next = nullptr;
                prev = nullptr;
            }

            Node()
            {
                val = 0;
                next = nullptr;
                prev = nullptr;
            }

            Node(int value, Node* nextPtr)
            {
                val = value;
                next = nextPtr;
                prev = nullptr;
            }
    };

    int maxCapacity = 0;
    int currentCapacity = 0;
    unordered_map<int,Node*> nodeMap;
    Node* tail;
    Node* head;

    void UpdateNodePosToLast(Node* newNode)
    {
        if(newNode==tail)
            return;

        //this node already exists in the list
        if(newNode->prev!=nullptr)
        {
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
            newNode->next = nullptr;
        }
        if(newNode==head)
        {
            newNode->next->prev = nullptr;
            head = newNode->next;
            newNode->next = nullptr;
        }
        if(tail==nullptr)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail=tail->next;
        tail->next=nullptr;
    }

    void RemoveHeadNode()
    {
        if(head==tail)
        {
            Node* tempNode = head;
            head=tail=nullptr;
            nodeMap.erase(tempNode->key);
            delete tempNode;
            currentCapacity--;
            return;
        }
            
        int keyValue = head->key;

        if(keyValue==-1)
            return;

        nodeMap.erase(keyValue);

        head->next->prev = nullptr;
        Node* nodeToDelete = head;

        head=head->next;

        delete nodeToDelete;
        currentCapacity--;
    }
    
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = tail = nullptr;
    }
    
    int get(int key) {
        
        if(nodeMap.count(key))
        {
            int valToReturn = nodeMap[key]->val;
            UpdateNodePosToLast(nodeMap[key]);
            return valToReturn;
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        if(nodeMap.count(key))
        {
            nodeMap[key]->val = value;
            UpdateNodePosToLast(nodeMap[key]);
        }
        else
        {
            if(currentCapacity>=maxCapacity)
            {
                RemoveHeadNode();
            }   

            Node* newNode = new Node(value,key);
            UpdateNodePosToLast(newNode);
            nodeMap[key] = newNode;
            currentCapacity++;
        }
    }
};
