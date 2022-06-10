class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int w1 = -1;
        int w2 = -1;
        int min_dist = INT_MAX;
        for (int i = 0; i < wordsDict.size();i++) {
            if (word1 == wordsDict[i]) {
               w1 = i;
            }
            else if (word2 == wordsDict[i]) {
               w2 = i;
            }
            if (w1 != -1 && w2 != -1) {
                min_dist = min(min_dist, abs(w1 - w2));
            }
        }
        return min_dist;
    }
};
