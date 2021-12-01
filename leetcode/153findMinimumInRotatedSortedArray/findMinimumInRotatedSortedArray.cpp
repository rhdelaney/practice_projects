class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[0];
        //alt option for problems w/o using sort ->
        //while l < r ->
        //wait until you find l > r ->
        //this will be where the list was last rotated
        //return the right value
        //if this never occurs return 0 index
        //this leads to a better time complexity
    }
};
