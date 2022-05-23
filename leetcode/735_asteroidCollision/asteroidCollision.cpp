class Solution {
public:
    vector<int> asteroidCollision(vector<int>& at) {
        stack<int>st;
        for (int i = at.size() - 1; i >= 0; i--){
            if (at[i] < 0)
                st.push(i);
            else {
                while ((!st.empty()) && (abs(at[st.top()]) < at[i])) {
                    at[st.top()] = 0;
                    st.pop();
                }
                if (!st.empty()) {
                    if (abs(at[st.top()]) == at[i]) {
                        at[i] = 0;
                        at[st.top()] = 0;
                        st.pop();
                    }
                    else at[i] = 0;
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i < at.size(); i++){
            if (at[i] != 0)
                ans.push_back(at[i]);
        }
        return ans;
    }
};
