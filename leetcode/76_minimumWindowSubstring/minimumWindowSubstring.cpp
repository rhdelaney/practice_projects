class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> mp1;
        unordered_map <char, int> mp2;
        int slow = 0,fast = 0,letterCounter = 0;
        int check = INT_MAX;
        string result;
        if (s == t) {
            return s;
        }
        for (auto ch: t) {
            mp1[ch]++;
        }
        for (; fast < s.size(); fast++) {
            char ch = s[fast];
            if (mp1.find(ch) != mp1.end()) {
                mp2[ch]++;
                if (mp2[ch] <= mp1[ch])
                  letterCounter++;
            }
            if (letterCounter >= t.length()) {
              while (mp1.find(s[slow]) == mp1.end() || mp2[s[slow]] > mp1[s[slow]]) {
                  mp2[s[slow]]--;
                  slow++;
                }
                if (fast - slow + 1 < check) {
                    check = fast - slow + 1;
                    result = s.substr(slow,check);
                }
            }
        }
        return result;
    }
};
