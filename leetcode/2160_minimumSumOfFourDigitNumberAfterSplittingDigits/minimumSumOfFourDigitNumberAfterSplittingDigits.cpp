class Solution {
public:
    int minimumSum(int num) {
        string temp = to_string(num);
        sort(temp.begin(), temp.end());
        return stoi(temp.substr(0, 1) + temp.substr(2, 1)) +
           stoi(temp.substr(1, 1) + temp.substr(3, 1));
    }
};
