class Solution {
public:
    bool valid (string s, int i, int j) {
        //do the same thing but return false if it happens again
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
      int i = 0;
      int j = s.size() -1;
      //2 pointers loop through
      while (i < j) {
          //when it isn't a palindrome -> remove a character & check
          if(s[i] != s[j]) {
              return valid(s, i, j-1) || valid(s, i+1, j);
          }
          i++;
          j--;
      }
      return true;
    }
};
        /*
       string str2 = s;
       reverse(str2.begin(), str2.end());
       if (str2 == s) {
           return true;
       }
       for (int i = 0; i < s.size(); i++) {
           if (s[i] != str[i]) {
               //delete
               //reverse
               //return check
               return
           }
       }
       return  false;
    }
}; */
