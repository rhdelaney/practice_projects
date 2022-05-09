class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> progress;
    for (int i = 0;i<nums.size();i++) {
        progress.push_back(nums[i]*nums[i]);
    }
    sort(progress.begin(),progress.end());
    return progress;
  }
};
