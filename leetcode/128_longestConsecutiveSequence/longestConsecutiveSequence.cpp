class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       /*sort(nums.begin(),nums.end());
       int start = nums[0];
       int counter = 0;
       int max_v = 0;
       for(int i = 1; i<nums.size();i++) {
           if (nums[i] > start) {
               if (nums[i] == start + 1) {
                   counter++;
               }
               else {
                   start = nums[i];
                   max_v = max(max_v,counter);
                   counter = 0;
               }
           }
       }
       return max_v; */
    if (!size(nums))
        return 0;
	sort(begin(nums), end(nums));
	int longest = 0;
    int cur_longest = 1;
	for(int i = 1; i < size(nums); i++)
		if (nums[i] == nums[i - 1])
            continue;
		else if (nums[i] == nums[i - 1] + 1)
            cur_longest++;
        // consecutive element - update current streak length
		else {
            longest = max(longest, cur_longest);
            cur_longest = 1;
        }
        // reset current streak length
	return max(longest, cur_longest);
    }
};
