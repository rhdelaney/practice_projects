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
    bool isPalindrome(ListNode* head) {
       ListNode *fast = head;
       ListNode *slow = head;
       ListNode *prev = NULL;
       ListNode *tmp;
       ListNode *reversed = NULL;
       //find the midpoint && store the first half of the list in reverse order
       while (fast != nullptr && fast->next !=nullptr) {
         fast = fast->next->next;
         prev = reversed;
         reversed = slow;
         slow = slow->next;
         reversed->next = prev;
       }
       slow = (fast ? slow->next : slow); // for odd length case as mentioned above
       //trace through the front
       while (reversed != nullptr) {
           if (reversed->val != slow->val) {
               return false;
           }
           reversed = reversed->next;
           slow = slow->next;
       }
       return true;
    }
};
