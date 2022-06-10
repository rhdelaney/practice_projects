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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        int start = 0;
        int last = lists.size() -1;
        int temp;
        while (last != 0) {
            start = 0;
            temp = last;
            while (start < temp) {
                lists[start] = merge(lists[start],lists[temp]);
                start++;
                temp--;
                if (start >= temp) {
                    last = temp;
                }
            }
        }
        return lists[0];
    }
    ListNode *merge(ListNode *l1, ListNode *l2) {
       ListNode *result = NULL;
       if (l1 == NULL) {
           return l2;
       }
       if (l2 == NULL) {
           return l1;
       }
       if (l1->val <= l2->val) {
          result = l1;
          result->next = merge(l1->next, l2);
       }
       else {
          result = l2;
          result->next = merge(l1, l2->next);
       }

       return result;
    }
};
