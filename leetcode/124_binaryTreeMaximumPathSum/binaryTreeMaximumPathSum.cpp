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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        max_path(root);
        return max_sum;
    }
    int max_path(TreeNode* root) {
      if (!root) {
          //base case
          return 0;
      }
      //left traverse & add up the sides
      int l = max(max_path(root->left),0);
      //right traverse & add up the sides
      int r = max(max_path(root->right),0);
      //curr node + the left and right nodes/traverse
      int price = root->val + l + r;
      //compare the current subtree to the other subtree sums
      //set the biggest to max sum
      max_sum = max(max_sum, price);
      //return the sum tree's value + the node
      return root->val + max(l,r);
    }
};
