class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool wordFound = false;
        for (int i = 0; i < board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                 if (findWord(board, i, j, word, 0))
                        return true;
            }
        }
        return wordFound;
    }
    bool findWord(vector<vector<char>>& board,int i,int j, string word, int place) {
        if (word.length() == place) {
           return true;
        }
        if (i < 0 ||  j < 0 || i >= board.size() || j >= board[0].size()){
            return false;
        }
        if (board[i][j] == word[place]) {
            //make a temp value for the board
            char temp = board[i][j];
            //this allows us to backtrack after calls.
            board[i][j] = '0';
            if(findWord(board, i + 1, j, word, place + 1) ||
                   findWord(board, i, j+1, word, place + 1) ||
                   findWord(board, i-1, j, word, place + 1) ||
                   findWord(board, i, j-1, word, place + 1)) {
                return true;
            }
            board[i][j] = temp;
        }
        return false;
    }
};
