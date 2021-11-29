class NumArray {
public:
    vector<int>numArray;
    NumArray(vector<int>& nums) {
        numArray = nums;
        for (int i = 1; i< nums.size();i++) {
            numArray[i] = nums[i] + numArray[i-1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return numArray[right];
        }
        return numArray[right] - numArray[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
