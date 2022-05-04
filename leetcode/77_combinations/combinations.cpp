class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        comb(res,tmp, n, k, 1);
        return res;
    }
    void comb(vector<vector<int>>& res,vector<int>&tmp, int num, int length, int indx) {
        if (tmp.size() == length) {
            res.push_back(tmp);
            return;
        }
        //loop like you wanted to before from indx to i == num
        for (int i = indx; i < num + 1; i++) {
            //temporarily push the number on the vector
            tmp.push_back(i);
            //send it into recursion -> a new vector
            comb(res,tmp, num, length, i+1);
            //pop the value off as you are for looping
            //this is the backtrack step
            tmp.pop_back();
        }
    }
};
