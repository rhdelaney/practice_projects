class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      //sort the array
      sort(begin(nums), end(nums));
      vector<vector<int>> res;
      for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
        //handle duplicate #'s and zero cases via remove/ignore
        if (i == 0 || nums[i - 1] != nums[i]) {
          twoSumII(nums, i, res);
        }
      return res;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>> &res) {
      //initialize the low & high pointers
      int lo = i + 1, hi = nums.size() - 1;
      while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
          //move left in
          ++lo;
        }
        else if (sum > 0) {
          //move right in
          --hi;
        }
        else {
          //found a triplet so add it to the list - inc & dec pointers
          res.push_back({ nums[i], nums[lo++], nums[hi--] });
          //clear more duplicates
          while (lo < hi && nums[lo] == nums[lo - 1])
            ++lo;
        }
      }
    }
};
