class Solution {
public:
    string addStrings(string num1, string num2) {
      string res;
      int sum = 0;
      //set up to iterate backwards
      int i = num1.size() - 1;
      int j = num2.size() - 1;
      //while loop until one side or both is finished
      while (i >= 0 && j >= 0) {
          //add these two values integers together - add by string character to get that
          sum += (num1[i--] - '0') + (num2[j--] - '0');
          //push back that values lower digit as the higher needs to be carried over
          res.push_back(char(sum%10 + '0'));
          //carry over
          sum = sum/10;
      }
      //work through the leftovers of num1
      while (i >= 0) {
          sum += (num1[i--] - '0');
          res.push_back(char(sum%10 + '0'));
          sum = sum/10;
      }
      //or work through the leftovers of num2
      while (j >= 0) {
          sum += (num2[j--] - '0');
          res.push_back(char(sum%10 + '0'));
          sum = sum/10;
      }
      //if there is any leftovers of sum you need to add a digit
      if (sum > 0) {
          res.push_back(char(sum%10 + '0'));
      }
      //flip the string around to the correct order
      reverse(res.begin(), res.end());
      return res;
   }
};
