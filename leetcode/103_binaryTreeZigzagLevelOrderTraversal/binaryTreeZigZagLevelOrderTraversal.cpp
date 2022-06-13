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
    vector<vector<int>> l;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if (!root) {
          return {};
      }
      level(root,0);
      for (int i = 1; i<l.size();i+=2) {
          reverse(l[i].begin(),l[i].end());
      }
      return l;
    }
    void level(TreeNode* root,int lev) {
        if (!root)
          return;
        if (lev == l.size())
            l.push_back({});
        l[lev].push_back(root->val);
        level(root->left, lev+1);
        level(root->right,lev+1);
    }
};
