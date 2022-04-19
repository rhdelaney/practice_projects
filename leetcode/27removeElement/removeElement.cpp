class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; //spot in nums array
        for (int i = 0; i< nums.size();i++) {
            if (nums.at(i) != val) {
                nums.at(j) = nums.at(i);
                j++;
            }
        }
        return j;
    }
};
