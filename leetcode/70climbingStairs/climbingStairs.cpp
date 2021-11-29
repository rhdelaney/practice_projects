class Solution {
public:
    //Constraints is 1 to 45
    int dp[46];
    int climbStairs(int n) {
        //if we already calculated the problem for that value
        if (dp[n] != 0) {
            return dp[n];
        }
        //the only two options for stairs climbed
        if (n == 1 || n == 2) {
            return n;
        }
        //create the summation of the problem and add to dp[n]
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        //return the stored value at "n"
        return dp[n];
    }
};
