//Complexity
//Time = O(N)
//Space = O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
      int count = 0;
      int prev = 0;
      int curr = 1;
      int i = 1;
      while (i < s.length()) {
          if (s.at(i-1) != s.at(i)) {
            count += min(prev,curr);
            prev = curr;
            curr = 1;
          }
          else {
            curr++;
          }
          i++;
      }
      return count += min(prev,curr);
    }
};
