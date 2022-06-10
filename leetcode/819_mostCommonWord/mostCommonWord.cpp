class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string tmp = "";
        int count = 0;
        unordered_map<string, int> mp;
        int i = 0;
        while (i < paragraph.size()) {
            tmp = "";
            while (i < paragraph.size() && isalpha(paragraph[i])) {
                tmp += tolower(paragraph[i]);
                i++;
            }
            if (tmp != "") {
                mp[tmp]++;
            }
            i++;
        }
        for (auto& s: banned) {
            mp.erase(s);
        }
        for (auto& [key,value] : mp) {
            if (count < value) {
                tmp = key;
                count = value;
            }
        }
        return tmp;
    }
};
