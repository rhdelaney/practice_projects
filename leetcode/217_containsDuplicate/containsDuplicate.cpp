class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int prevVal = -1;
    bool checker = false;
    for (int i = 0; i<nums.size(); i++) {
        if (prevVal != nums[i]) {
            prevVal = nums[i];
        }
        else {
            return true;
        }
    }
    return checker;
  }
};
