class Solution {
public:
    int maxArea(vector<int>& height) {
        //make two indexes for the pointers
        int left = 0;
        int right = height.size()-1;
        //return value
        int max_area = 0;

        while (left < right) {
            //left side value
            int lh = height[left];
            //right side value
            int rh = height[right];
            //forumula = index of right minus left
            //times the minimum of the left vs right side
            //set to the max area
            max_area = max(max_area,(right-left) * min(lh,rh));

            if (lh < rh)
                ++left;
            else
                --right;
        }
        return max_area;
    }
};
