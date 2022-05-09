/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //it's a binary search tree ->
    //what we know abou bst's
    //left is less than root
    //right is greater than root
    //using this we can find the LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //are both nodes less than this leaf value
        //if so we can traverse deeper
        if (root->val > p->val && root->val > q->val) {
           return lowestCommonAncestor(root->left,p,q);
        }
        //are both nodes greater than this leaf value
        //if so we can traverse deeper
        else if (root->val < p->val && root->val < q->val) {
           return lowestCommonAncestor(root->right,p,q);
        }
        //else we are at the LCA
        else {
          return root;
        }
    }
};
