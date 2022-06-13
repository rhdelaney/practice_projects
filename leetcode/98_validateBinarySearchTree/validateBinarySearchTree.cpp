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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        bool valid = checkValid(root);
        return valid;
    }
    bool checkValid(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if ((root->left != NULL && root->left->val > root->val) || (root->right != NULL && root->right->val < root->val)) {
            return false;
        }
        return checkValid(root->left) && checkValid(root->right);

    }
};
