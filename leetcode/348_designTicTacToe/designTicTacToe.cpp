class TicTacToe {
public:
//Complexity
//Time: O(1)
//space: O(n)
    vector<int> cols;
    vector<int> rows;
    int diag = 0;
    int anti_diag = 0;
    TicTacToe(int n) {
      cols.assign(n,0);
      rows.assign(n,0);
    }

    int move(int row, int col, int player) {
        int val = 1;
        if (player == 2) {
            val = -1;
        }
        rows[row] += val;
        cols[col] += val;
        if (row == col) {
            diag += val;
        }
        int n = rows.size();
        if (row == n - col - 1) {
            anti_diag += val;
        }
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(anti_diag) == n) {
            return player;
        }
        else {
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
