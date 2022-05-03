class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> v(3,vector<int>(3, -1));
        for (int i = 0; i<moves.size();i++) {
            if(i % 2 == 0) {
               v[moves[i][0]][moves[i][1]] = 1;
            }
            else {
                v[moves[i][0]][moves[i][1]] = 0;
            }
        }
        for (int i = 0;i < 3;i++){
            if (v[i][0] != -1 && v[i][0] == v[i][1] && v[i][1] == v[i][2])
                return {v[i][0] == 1? 'A' : 'B'};
            if (v[0][i] != -1 && v[0][i] == v[1][i] && v[1][i] == v[2][i])
                return {v[0][i] == 1? 'A' : 'B'};
        }
        if (v[0][0] != -1 && v[0][0] == v[1][1] && v[1][1] == v[2][2]) return {v[0][0] == 1? 'A' : 'B'};
        if (v[0][2] != -1 && v[0][2] == v[1][1] && v[1][1] == v[2][0]) return {v[0][2] == 1? 'A' : 'B'};
        //2 players
        //A is X
        //B is O
        //ends when 3 fill row, column or diagonal
        //ends if non-empty grid
        //moves[i] = [row][column]
        //A plays first -> x first
        return (moves.size() == 9) ? "Draw":"Pending";
    }
};
