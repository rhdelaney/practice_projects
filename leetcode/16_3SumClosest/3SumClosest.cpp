class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       //do three sum
       //once you hit midpoint you compare to previous min
       //difference between target min_val = min(min_val,abs(total-target));
       if (nums.size() < 3) {
           return 0;
       }
       sort(nums.begin(), nums.end());
       int min_val = INT_MAX;
       int ans = 0;
       for (int i = 0; i< nums.size() - 2; i++) {
           int firstVal = nums[i];
           int sum = 0;
           int front = i + 1;
           int back = nums.size() - 1;
           while (front < back) {
               sum = firstVal + nums[front] + nums[back];
               if (abs(target - sum) < min_val) {
                  min_val = abs(target - sum);
                  ans = sum;
               }
               else if (sum > target) {
                   back--;
               }
               else {
                   front++;
               }
           }
       }
       return ans;
    }
};
