class Solution {
public:
    vector<string> letterCasePermutation(string s) {
       vector<string> res;
       //go through list
       //
       perm(s,res,0);
       /*
       for (int i = 0; i < s.length(); i++) {
          if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
              addLetter(res,s[i]);
          }//check if letter
          else {
              addNumber(res,s[i]);
          }
       }*/
       //check if letter
       //add a new string for lowercase & one for upper case
       //for all existing strings in the return vector
       //return said vector
        return res;
    }
    void perm(string s,vector<string>& res, int i) {
        //base case
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        //check if character
        if (isalpha(s[i])) {
            //upper case it
            s[i] = toupper(s[i]);
            //make a new perm for it
            perm(s,res,i+1);
            //lower case it
            s[i] = tolower(s[i]);
            //make a new perm for it
            perm(s,res,i+1);
        }
        else {
            //if it's a number just move along
            perm(s,res,i+1);
        }
    }
    /*
    void addNumber(vector<string>& res, char c) {
        for (int i = 0; i < res.size(); i++) {
            res[i].push_back(c);
        }
    }
    void addLetter(vector<string>& res, char c) {
        //make copies of all the strings in res
        //append upper case to half and lower case to half
        int n = res.size();
        for(int i = 0; i < n; i++) {
            string tmp = res[i];
            tmp.push_back(toupper(c));
            res[i].push_back(tolower(c));
            res.push_back(tmp);
        }
    }*/
};
