class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perm(res,nums,0);
        return res;
    }
    void perm(vector<vector<int>>& res,vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        //for loop through
        for (int i = index; i < nums.size(); i++) {
            //switch the point you are at with each element in
            //the list
		    swap(nums[index], nums[i]);
            //this makes a new res
		    perm(res, nums, index + 1);
		    // this is the backstep step
            // as we want to keep the og state
		    swap(nums[index], nums[i]);
		}
    }
};
