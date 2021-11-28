class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            // ^ is xor & is and | is or use the operators
            //XOR OPERATIONS CANCEL EACH OTHER OUT
            ans ^= nums[i];
        }
        return ans;
    }
};
