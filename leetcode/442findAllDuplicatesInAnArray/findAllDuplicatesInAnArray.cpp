class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int> ans;
      for (int i = 0; i< nums.size();i++) {
          /*if (hash[nums[i]] == 1) {
              ans.push_back(nums[i]);
          }
          else {
              hash[nums[i]] = 1;
          }*/
          if (nums[abs(nums[i])-1] < 0)                    // if visited push to vector
             ans.push_back(abs(nums[i]));
          nums[abs(nums[i])-1]*=-1;                    // mark as visited
      }
      return ans;
    }
};
