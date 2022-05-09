class Solution {
public:
    int trap(vector<int>& height) {
      //set left and rigtht arrays for filling area
      int left[height.size()];
      int right[height.size()];
      //this step allows us to move one in for each array filling
      left[0] = height[0];
      right[height.size() - 1] = height[height.size() - 1];
      //fill the left array with the max value left to right
      for (int i = 1; i < height.size(); i++) {
          left[i] = max(left[i - 1], height[i]);
      }
      //fill the right array with max value right to left
      for (int i = height.size() - 2; i >= 0; i--) {
          right[i] = max(right[i + 1], height[i]);
      }
      int ans = 0;
      //now use this to find the min of max heights to get a range for
      //the water being trapped.
      for (int i = 0; i < height.size(); i++) {
          ans += (min(left[i],right[i]) - height[i]);
      }
      return ans;
    }
};
