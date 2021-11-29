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
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode *> q;
      q.push(root);
      TreeNode *tmp;
      double temp;
      vector<double>res;
      int size = 0;
      while (!q.empty()) {
          temp = 0;
          size = q.size();
          for(int i = 0; i< size;i++) {
              tmp = q.front();
              q.pop();
              if (tmp->left) {
                  q.push(tmp->left);
              }
              if (tmp->right) {
                  q.push(tmp->right);
              }
              temp +=tmp->val;
          }
          res.push_back((double)temp / size);
      }
        return res;
    }
};
