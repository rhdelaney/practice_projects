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
        if (head == nullptr) return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        int val = -101;
        while (temp != nullptr) {
            if (temp->val == val) {
                prev->next = temp->next;
                temp = temp->next;
            }
            else {
                val = temp->val;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
