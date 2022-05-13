class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        unordered_map<char,int> freq;
        for(int i =0; i< magazine.size();i++) {
            freq[magazine[i]]++;
        }
        for (int j = 0; j < ransomNote.size(); j++) {
            if (freq[ransomNote[j]] > 0) {
                freq[ransomNote[j]]--;
            }
            else {
                return false;
            }

        }
        return true;
    }
};
