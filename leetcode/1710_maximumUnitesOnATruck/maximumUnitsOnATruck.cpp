bool cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
}
class Solution {
public:
//Time Complexity:
//Time: O(n log n)
//Space: O(1)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort by highest units per box
        //simple equations
        int units = 0;
        sort(boxTypes.begin(),boxTypes.end(), cmp);
        for (int i = 0; i < boxTypes.size();i++) {
            if (truckSize > boxTypes[i][0]) {
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                units += truckSize * boxTypes[i][1];
                truckSize = 0;
                break;
            }
        }
        return units;
    }
};
