class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int ptr = 0;
        int num = 0;
        // loop through the array
        for (int i = 0; i < abbr.size(); i++) {
            //is it a character
            if (isalpha(abbr[i])) {
                //add num to this pointer
                ptr += num;
                //set num to 0
                num = 0;
                //if ptr is less than word size it's still in string
                // if it's equal to the value in abbr that is good keep the pointer moving
                if (ptr < word.size() && abbr[i] == word[ptr])
                    ptr += 1;
                else
                    return false; //if not the problem isn't a valid abbreviation
            }
            else {
                if (abbr[i] == '0' && num == 0) { //if the abbreviation starts with a zero (see num is at 0) -> it is invalid
                    return false;
                }
                else {
                    num = 10 * num + (abbr[i] - '0'); //if not we calculate the number value and store it into num
                }
            }
        } //if ptr location + num's value == word size it's valid
        return ptr + num == word.size();
    }
};
