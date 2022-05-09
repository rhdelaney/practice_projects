class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     //brute force ->
     //merge & sort then use the size to find the median
      int i = 0;
      int j = 0;
      int k = 0;
      int curr = 0;
      int prev = 0;
      while (i <= ((nums1.size() + nums2.size())/2)) {
        if (k >= nums2.size() || (j < nums1.size() && nums1[j]<nums2[k])) {
              prev = curr;
              curr = nums1[j++];
            }
            else {
              prev = curr;
              curr = nums2[k++];
            }
            i++;
      }
      if ((nums1.size() + nums2.size()) % 2 == 0) {
          return (double)(curr + prev)/2;
      }
      else {
          return (double)curr;
      }
    }
};
