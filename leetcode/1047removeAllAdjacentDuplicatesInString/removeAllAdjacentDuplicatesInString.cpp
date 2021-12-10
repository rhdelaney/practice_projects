class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        //for loop through the string at 1
        for (int j = 1; j < s.size(); j++) {
            //checks to make sure we don't have dupes
            if (i < 0 || s[i] != s[j]) {
                s[++i] = s[j];
            }
            else {
            //checking in reverse too
                --i;
            }
        }
        return s.substr(0,i+1);
    }
};
