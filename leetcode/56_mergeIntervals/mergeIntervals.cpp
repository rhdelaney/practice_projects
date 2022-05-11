class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //init result vector
        vector<vector<int>> res;
        //return if it's 1 interval or less
        if (intervals.size() <= 1) {
            return intervals;
        }
        //sort because they aren't given sorted
        sort(intervals.begin(),intervals.end());
        //push the first interval into the results array
        res.push_back(intervals[0]);
        //loop from the second value in
        for (int i = 1; i< intervals.size();i++) {
            //compare the last put into the results vector w/ the current value's range
            //to see if it's w/in the interval
            if (res.back()[1] >= intervals[i][0]) {
                //update the last value in the array if it's w/in
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            //else push the value into the array
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
