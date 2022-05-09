class Solution {
public:
    string removeDuplicates(string s, int k) {
        //create a final vector
        vector<int>vec(s.length(),0);
        int i = 0;
        //loop through
        while (i < s.length()) {
            //if the index is not equal to the previous count is 1
            if (i == 0 || s[i] != s[i-1])
                vec[i] = 1;
            else {
                //holding the count of frequency
                vec[i] = vec[i-1] + 1;
                //did we hit the expected count?
                if (vec[i] == k) {
                    //if so we set the count back to pre these characters
                    //as after we remove them the string starts there
                    i -= k;
                    //we erase the characters we don't need at that index
                    s.erase(i+1, k);
                }
            }
            i++;
        }
        return s;
    }
};
