class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
      long long int ans = 0;
      for (int i = 0; i < nums.size() ; i++) {
        int maxN = nums[i];
        int minN = nums[i];
        for (int j = i; j < nums.size(); j++) {
          maxN = max(maxN, nums[j]);
          minN = min(minN, nums[j]);
          ans += maxN - minN;
        }
     }
     return ans;
   }
};
