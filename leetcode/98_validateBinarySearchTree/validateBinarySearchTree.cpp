//**
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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool valid = checkValid(root, -1e18,1e18);
        return valid;
    }
    bool checkValid(TreeNode* root,long long int min,long long int max) {
        if (!root) {
            return true;
        }
        if (root->val>=max || root->val<=min) {
            return false;
        }
        return checkValid(root->left,min,root->val) && checkValid(root->right,root->val,max);

    }
};
