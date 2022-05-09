class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      set<int> s;
      unordered_map<int,int> m;
      for (int i = 0; i<arr.size(); i++) {
        m[arr[i]]++;
      }
      for (auto it = m.begin(); it != m.end(); it++) {
        s.insert(it->second);
      }
      if (m.size() == s.size())
        return true;
      return false;
    }
};
