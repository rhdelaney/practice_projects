class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int size = nums.size();
      sort(nums.begin(), nums.end());
      int i = 0;
      while(i < size) {
        if (nums[i] != i) {
          return i;
        }
        else {
          i++;
        }
      }
      return nums.size();
    }
};
