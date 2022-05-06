class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev = nums[0];
        int i = 1;
        if (nums.size() == 1) {
            return 0;
        }
        //want the variable where the values stop increasing
        while (i < nums.size()) {
            if (nums[i] < nums[i-1])  {
                return i - 1;
            }
            i++;
        }
        return i - 1;
    }
};
