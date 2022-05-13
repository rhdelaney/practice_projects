class Solution {
public:
    int longestPalindrome(string s) {
        // pattern recognization
        // need 2 chars for a pair
        // add 1 single char if available ->
        int pairCount = 0;
        unordered_map<char, int> freq;
        for (auto ch : s) {
            freq[ch]++;
            if (freq[ch] == 2) {
                pairCount++;
                freq.erase(ch); //better to delete here
            }
        }
        pairCount *= 2;
        return freq.size() > 0 ? pairCount + 1: pairCount;

    }
};
