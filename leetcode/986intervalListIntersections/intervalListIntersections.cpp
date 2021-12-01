class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       vector<vector<int>> res;
       if (firstList.size()==0 || secondList.size() == 0) {
           return res;
       }
       int i = 0;
       int j = 0;
       while (i < firstList.size() && j< secondList.size()){
           //need the biggest number first
           int l = max(firstList[i][0], secondList[j][0]);
           //need the smallest to find the end of the intersection
           int u = min(firstList[i][1], secondList[j][1]);
           //checks to make sure there is an intersection
           if (l <= u)
               res.push_back({l,u});
           //checks to make sure we don't miss the inbetween intersections
           if (firstList[i][1]<secondList[j][1])
               i++;
           else
               j++;
       }
        return res;
    }
};
