class Solution {
public:
    int rob(vector<int>& nums) {
        //dp requires vector ->
        if (nums.size() == 0) {
            return 0;
        }
        int prev1 = 0;
        int prev2 = 0;
        for (auto i : nums) {
            // previous max value
            int tmp = prev1;
            // calculate new max value w/ previous max(2) + value now vs current max(prev1)
            prev1 = max(prev2 + i, prev1);
            //need the tmp value for previous max
            prev2 = tmp;
        }
        return prev1;
        //case 1 : rob 0
        //case 2 : rob max(nums[0],nums[1])
        //case 3 : rob max(nums[0] + nums[2], nums[1])
        //case 4 : rob max(max(nums[0] + nums[2], nums[1] + nums[3]), nums[0] + nums[3]);
    }
             //same thing -> previous max + current value vs most recent max to find new
             //most recent max & store
            //sum += max(robbery(nums, i-2) + nums[i], robbery(nums,i-1));
};
