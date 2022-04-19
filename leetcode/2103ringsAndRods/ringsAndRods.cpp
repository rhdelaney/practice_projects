class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        //initialize maps
        int red[10] = {0};
        int blue[10] = {0};
        int green[10] = {0};
        //go through rings list
        for (int i = 0; i < n; i += 2) {
            if (rings[i] == 'R') {
                //if it's red add it as existing - it doesn't matter how many
                red[rings[i+1]-'0'] = true;
            }
            else if (rings[i] == 'B') {
                //if it's blue add it as existing - it doesn't matter how many
                blue[rings[i+1]-'0'] = true;
            }
            else if (rings[i] == 'G') {
                //if it's green add it as existing - it doesn't matter how many
                green[rings[i+1]-'0'] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++){
            //verify that all of these have a ring on that stand
            if (red[i] == 1 && green[i] == 1 && blue[i] == 1) {
                res++;
            }
        }
        return res;
    }
};
