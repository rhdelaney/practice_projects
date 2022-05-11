class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        for (int i =0; i<keyboard.size();i++) {
            m[keyboard[i]] = i;
        }
        int lastIdx = 0;
        int totalMoves = 0;
        for (int i = 0; i < word.size();i++) {
            totalMoves += abs(m[word[i]] - lastIdx);
            lastIdx = m[word[i]];
        }
        return totalMoves;
    }
};
