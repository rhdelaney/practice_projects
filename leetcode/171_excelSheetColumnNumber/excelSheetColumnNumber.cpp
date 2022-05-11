class Solution {
public:
    int titleToNumber(string columnTitle) {
        //go char by char
        //use base 27 as the idea that
        //once you go over to the next char you are 26*that letter's value
        //add to the next.
        int colNumber = 0;
        for (int i = 0; i< columnTitle.length();i++) {
            colNumber = colNumber * 26;
            colNumber += (columnTitle[i] - 'A' + 1);
        }
        return colNumber;
    }
};
