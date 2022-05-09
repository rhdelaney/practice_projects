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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k <= 1) //cant reverse
        return head;
      ListNode *nextHead = head;
      for (int i = 0; i<k; ++i) { //iterate until you should reverse
        if (!nextHead) //cant reverse end of list
          return head;
        nextHead = nextHead->next; //iterate
      }
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *following = nullptr;
        for(int i = 0; i < k; ++i) {
            following = curr->next; //set the next ptr to current's next
            curr->next = prev; //set current next to previous pointer
            prev = curr; //set previous ptr to the current ptr
            curr = following; //set the curr ptr to following(next pointer in list)
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
