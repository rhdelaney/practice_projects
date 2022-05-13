class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int countOfPairs = 0;
        vector<int>remainders(60,0);
        for (int i = 0; i < time.size(); i++) {
            /* algorithim is as follows:
            1. b % 60 = 0 if a % 60 = 0
            2. b % 60 = 60 - a % 60 if a % 60 != 0
            */
            if (time[i] % 60 == 0 ) {
                    countOfPairs += remainders[0];
            }
            else {
                countOfPairs += remainders[60 - time[i] % 60];
            }
            remainders[time[i] % 60]++;
        }
        return countOfPairs;
    }
};
