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
    int minDepth(TreeNode* root) {
       if (root == NULL) {
           return 0; //exit since there is no tree
       }
       if (root->left == NULL && root->right == NULL) {
           return 1; //exit since we hit a dead end
       }
       else if (root->left != NULL && root->right == NULL) {
           return minDepth(root->left) + 1; //hit a dead end on the right
           //we can keep checking the left
       }
       else if (root->left == NULL && root->right != NULL) {
           return minDepth(root->right) + 1; //hit a dead end on the left
           //we can keep checking the right
       }
       else {
           //both are null
           //take the lowest level value between the right & left & add 1
           return min(minDepth(root->left),minDepth(root->right))+1;
       }
    }
};
