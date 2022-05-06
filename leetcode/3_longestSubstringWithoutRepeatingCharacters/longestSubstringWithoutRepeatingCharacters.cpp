class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        map<char, int> characters;
        int max_sub = 0;
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (characters.find(s[i]) != characters.end()) {
                characters.find(s[i])->second++;
            }
            else {
              characters.insert(pair<char, int>(s[i], 1));
            }
            // ONLY if in HashTable exist several same characters:
            // decrease ALL characters between j and i in HashTable AND increase j for calculation while s[i] value in Hash table > 1
            while (characters.find(s[i])->second > 1 ) {
                // Descrease value of existing character
                characters.find(s[j])->second--;
                // Increase j for future calculation
                ++j;
            }
            // longest will be chosen between larger value: old longest OR current sequance (i - j + 1)
            max_sub = max(max_sub, i - j + 1);
        }
        return max_sub;
    }
};
