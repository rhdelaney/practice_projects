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
    ListNode* deleteDuplicates(ListNode* head) {
        //empty case -> return the head/NULL
        if (head == nullptr)
          return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        //minimum value = -100
        int val = -101;
        while (temp != nullptr) {
            //when it's the same value as before
            //it's a dupe so remove it
            if (temp->val == val) {
                prev->next = temp->next;
                temp = temp->next;
            }
            //if it's not the same value,
            //add it back and store the value for
            //the next loop
            else {
                val = temp->val;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
