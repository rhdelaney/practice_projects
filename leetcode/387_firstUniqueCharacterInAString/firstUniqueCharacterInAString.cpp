class Solution {
public:
//Run time:
//Time: O(N)
//Space O(1)
    int firstUniqChar(string s) {
        //create a map or a hashmap
        unordered_map<char,int> m;
        for (int i = 0; i< s.size();i++) {
            //increment the map at letter if it exists
            m[s[i]]++;
        }
        for (int i = 0; i< s.size();i++) {
            //looking for a unique character
            //in string which means it would
            //have a value of 1
            if (m[s[i]] == 1) {
                return i;
            }
        }
        //if it doesn't exist return -1
        return -1;
    }
};
