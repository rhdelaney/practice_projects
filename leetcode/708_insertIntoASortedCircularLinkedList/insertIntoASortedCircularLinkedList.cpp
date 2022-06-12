/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *ptr = head->next;
        Node *prev = head;
        bool toInsert = false;
       do {
            if (ptr->val >= insertVal && prev->val <= insertVal) {
                toInsert = true;
            }
            else if (ptr->val < prev->val) {
                if (insertVal >= prev->val || insertVal <= ptr->val) {
                    toInsert = true;
                }
            }
            if (toInsert) {
                prev->next = new Node(insertVal, ptr);
                return head;
            }
            prev = ptr;
            ptr = ptr->next;
        } while (prev != head);

        prev->next = new Node(insertVal,ptr);
        return head;
    }
};
