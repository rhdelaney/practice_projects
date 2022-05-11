class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        //track letter and frequency
        unordered_map<char,int> m;
        for (int i = 0; i<s.size();i++) {
            m[s[i]]++;
        }
        for (int j = 0; j<t.size(); j++) {
            if (m[t[j]]) {
                m[t[j]]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
