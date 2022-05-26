class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       unordered_map<char,int> mp;
       for (auto ch : chars) {
           mp[ch]++;
       }
       unordered_map<char,int> temp = mp;
       bool goodWord = true;
       vector<string> ans;
       int total = 0;
       for (auto word: words) {
           int i = 0;
           temp = mp;
           goodWord = true;
           while (i < word.size()) {
             if (temp.find(word[i]) == temp.end() || temp[word[i]] <= 0) {
                 i = word.size();
                 goodWord = false;
             }
             else {
                 temp[word[i]]--;
             }
             i++;
           }
           if (goodWord) {
               total += word.length();
           }
       }
       return total;
    }
};
