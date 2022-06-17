class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
       backtracking(n, "", 0, 0);
       return res;
    }
    void backtracking(int n, string paren, int open, int closed) {
        if (paren.length() == n * 2) {
            res.push_back(paren);
            return;
        }
        if (open < n) {
            backtracking(n, paren+"(",open+1,closed);
        }
        if (closed < open) {
            backtracking(n, paren+")",open, closed+1);
        }
    }
};
