class Solution {
public:
    //WIP
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1)
            return {{strs[0]}};
        //ans will hold a vector of vector of strings {[bat],[nat,tan]}
        vector<vector<string>> ans;
        //m will hold the sorted string and all the values in strs that share this
        //sorted string(are anagrams)
        unordered_map<string, vector<string>> m;
        //loop through
        for (int i = 0; i < strs.size();i++) {
            //make a copy
            string tmp = strs[i];
            //sort the string
            sort(strs[i].begin(),strs[i].end());
            //let the sorted string be the key and the original value be pushed into
            //the vector
            m[strs[i]].push_back(tmp);
        }
        //iterate through and push the vector the key holds as the output since
        //it's a vector of strings
        for(auto i = m.begin(); i != m.end(); i++)
            ans.push_back(i -> second);  // Traversing the map and adding the vectors of string to ans
        return ans;

    }
};
