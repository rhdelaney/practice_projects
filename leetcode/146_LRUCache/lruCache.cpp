class LRUCache {
public:
//Complexity
//Time: O(1)
//Space: O(capacity)
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int key, int val) {
                this->key = key;
                this->val = val;
            }
    };
    //two dummy nodes to keep track starting and ending point of list
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int capacity;
    unordered_map<int,node*> map;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node* curNode) {
        node* prevNode = curNode->prev;
        node* nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    // function to help a node in the next to head [can say front of our list]
    void addNode(node* curNode) {
        curNode->next = head->next;
        curNode->prev = head;
        curNode->next->prev = curNode;
        head->next = curNode;
    }

    int get(int key) {
       // if key is not present than return -1;
        if (map.find(key) == map.end())
          return -1;
        //if key is present , than update the node and return the value associated with the key
        // for update first we remove the node and then add at start of list with the help of insert function
        node* curNode = map[key];
        int result = curNode->val;
        map.erase(key);
        deleteNode(curNode);
        addNode(curNode);
        map[key] = head->next;
        return result;
    }

    void put(int key, int value) {
      //if key is already present than we have to update it
      // similiary we first remove and then add node in front with the help of insert helper
        if (map.find(key) != map.end()) {
            node* curNode = map[key];
            map.erase(key);
            deleteNode(curNode);
        }
        // if size is full then we have to remove the least recently used node
        if (map.size() == capacity) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
