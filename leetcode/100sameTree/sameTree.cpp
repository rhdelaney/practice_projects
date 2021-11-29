/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //boundary check - both null -> true
        if (p == NULL && q == NULL) {
            return true;
        }
        //boundary check - one null and one not is not the same tree
        else if ((p == NULL && q != NULL) || (q == NULL && p !=NULL)) {
            return false;
        }
        return checkTree(p, q);
    }
    bool checkTree(TreeNode* p, TreeNode *q) {
        //finished checking the branch and it matches
        if (p == NULL && q == NULL) {
            return true;
        }
        //checked branch and one is null and one isn't -> doesn't match
        else if ((p == NULL && q != NULL) || (q == NULL && p !=NULL)) {
            return false;
        }
        //checked branch and the values aren't the same -> doesn't match
        else if (p->val != q->val) {
            return false;
        }
        else {
            //both cases/branchees need to match to be true -> recursively check both
            return checkTree(p->left, q->left) && checkTree(p->right, q->right);
        }
    }
};
