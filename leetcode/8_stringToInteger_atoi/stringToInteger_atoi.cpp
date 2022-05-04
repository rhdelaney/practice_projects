class Solution {
public:
//Time Complexity:
//Time: O(N)
//Space: O(1)
    int myAtoi(string s) {
        int i = 0;
        while (s.size() > i) {
          if (s[i] == ' ') {
             i++;
          }
          else {
              break;
          }
        }
        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        }
        else if (s[i] == '+')
            i++;
		//this string will be used to extract out the part which need to be converted and
		//rest of the string will be ignored
        string str = "";
        while (i < s.size()) {
            if (s[i] != '0')
                break;
            else
                i++;
        }
        while (s.size() > i) {
          if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
             str += s[i];
             i++;
          }
          else {
              break;
          }
        }
        int p = 0;
        long long res = 0;
        bool ovf = false;
        for(int i = str.size() - 1;i >= 0 ;i--)
        {
			//converting the values to int and then multiplying by
			//corrent power of 10 so as to get that value at correct position
            int val = str[i] - '0';
            res += val * pow(10,p);
            p++;
			if ((p > 10) or res > INT_MAX) {
                ovf = true;
                break;
            }
        }
		//in case there is overflow, we return the values accordingly
        if (ovf) {
            if (neg)
                return INT_MIN;
            else
                return INT_MAX;
        }
        if (neg)
            return -res;
        else
            return res;
    }
};
