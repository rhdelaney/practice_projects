class Solution {
public:
    bool check(int a[26],int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        //if the second is bigger than the first it can't be inside of the other
        if (s.length() < p.length())
            return {};
        string temp = "";
        //26 letters in alphabet
        int a[26] = {0}, b[26] = {0};
        //fill the array up
        for (auto x:p) {
            a[x-'a']++;
        }
        int k = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i >= p.length()) {
                if (check(a,b))
                  v.push_back(i-p.length());
                if (i >= s.length())
                    break;
                b[s[i - p.length()] - 'a']--;
                b[s[i] - 'a']++;
            }
            else
                 b[s[i] - 'a']++;
        }
        return v;
    }
};
