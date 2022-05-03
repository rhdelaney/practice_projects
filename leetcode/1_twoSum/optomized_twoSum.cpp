//Time Complexity = O(N)
//Space Complexity = O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> map;
      for (int i=0; i < nums.size();i++) {
          int curr = nums[i];
          int x = target - curr;
          if (map.count(x)) {
              return {i,map[x]};
          }
          else {
              map[curr] = i;
          }
      }
      return {-1,-1};
    }
};
