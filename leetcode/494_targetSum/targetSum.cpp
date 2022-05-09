class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return sumToTarget(nums, 0, target);
    }
    int sumToTarget(vector<int>& nums, int i, int sum) {
        if (i == nums.size())
            return sum == 0;
        return sumToTarget(nums, i+1, sum+nums[i]) + sumToTarget(nums, i+1, sum-nums[i]);
    }
};
