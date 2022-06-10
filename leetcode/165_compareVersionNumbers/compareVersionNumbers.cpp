class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int number1 = 0, number2 = 0;
        while (i < version1.length() || j < version2.length()) {
            string tmp1 = "";
            string tmp2 = "";
            while (i < version1.length() && version1[i] != '.') {
                 number1 = number1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < version2.length() && version2[j] != '.') {
                 number2 = number2 * 10 + (version2[j] - '0');
                j++;
            }
            if (number1 > number2) {
                return 1;
            }
            else if (number1 < number2) {
                return -1;
            }
            number1 = 0, number2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};
