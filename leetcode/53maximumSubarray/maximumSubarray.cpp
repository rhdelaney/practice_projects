class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
          //find if the local max + nums[i] > the max
          local_max = max(nums[i], local_max + nums[i]);
          //see if the current local_max > the max sum found so far
          max_sum = max(max_sum,local_max);
        }
        return max_sum;
    }
};
