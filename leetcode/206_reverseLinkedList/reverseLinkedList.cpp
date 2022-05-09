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
    ListNode* reverseList(ListNode* head) {
        ListNode *n = NULL;
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur != nullptr) {
            n = cur->next; //save the next node
            cur->next = prev; //set the previous node's value to the next in curr list
            prev = cur; //store the cur next as the previous node
            cur = n; //set to next node in list
        }
        return prev;
    }
};
