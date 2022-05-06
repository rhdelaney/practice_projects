class Solution {
public:
    bool isPalindrome(string s) {
      //convert all of it to lower
      transform(s.begin(),s.end(),s.begin(), ::tolower);
      string str = "";
      for (int i = 0; i < s.length(); i++) {
          //take out the trash values
          if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
              str +=s[i];
          }
      }
      string str2 = str;
      //reverse this final string
      reverse(str.begin(), str.end());
      //compare
      return str == str2;
    }
};
