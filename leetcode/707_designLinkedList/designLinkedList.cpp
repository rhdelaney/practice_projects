class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node *head = new Node(0);
    MyLinkedList() {
    }

    int get(int index) {
        if (index >= size)
            return -1;
        Node *tmp = head->next;
        for (int i = 0 ; i < index ; i++)
            tmp = tmp->next;
        return tmp->val;
    }

    void addAtHead(int val) {
        Node *tmp = head->next;
        head->next = new Node(val);
        head->next->next = tmp;
        size++;
    }

    void addAtTail(int val) {
        Node *ptr = head;
        Node *tmp = new Node(val);
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = tmp;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        Node* ptr = head;
        for (int i = 0 ; i < index ; i++)
            ptr = ptr->next;
        Node *tmp = ptr->next;
        ptr->next = new Node(val);
        ptr->next->next = tmp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size)
            return;
        Node *ptr = head;
        for (int i = 0 ; i < index ; i++)
            ptr = ptr->next;
        Node *tmp = ptr->next;
        ptr->next = tmp->next;
        tmp->next = NULL;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
