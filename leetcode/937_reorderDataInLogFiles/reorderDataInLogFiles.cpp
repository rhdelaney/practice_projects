class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        multiset<string> letLogs;
        vector<string> digLogs;
        vector<string> ans;
        string identifier;
        for (int i = 0; i < logs.size(); i++) {
            int pos = logs.at(i).find(" ");
            identifier = logs.at(i).substr(0,pos);
            if (logs.at(i)[pos+1] >= '0' && logs.at(i)[pos+1] <= '9') {
                digLogs.push_back(logs.at(i));
            }
            else {
                letLogs.insert(logs.at(i).substr(pos) + "  " + identifier);
            }
        }
        for (auto i : letLogs){
            ans.push_back(i.substr(i.find("  ")+2) + i.substr(0, i.find("  ")));
        }
        for(int i = 0; i< digLogs.size();i++) {
            ans.push_back(digLogs.at(i));
        }
        return ans;
       //letter logs -> letters
       //digit logs -> numbers
       //put letter logs before digit logs
       //put letter logs in lexicographical order by identifiers
    }
};
