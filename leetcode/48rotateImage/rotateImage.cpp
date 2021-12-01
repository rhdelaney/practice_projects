class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     /* for (int i = 0;i < matrix.size();i++) {
          for(int j = i; j< matrix.size();j++) {
              swap(matrix[i][j],matrix[j][i]);
          }
      }
      for (int i = 0;i < matrix.size();i++) {
              reverse(matrix[i].begin(),matrix[i].end());
          } */
    int rows = size(matrix), tmp;
	for(int i = 0; i < rows / 2; i++){
		for(int j = i; j < rows - 1 - i; j++) {
            //store value at cell
			tmp = matrix[i][j];
            //set cell to value of transposed cell
			matrix[i][j] = matrix[rows - 1 - j][i];
            //set the cell you used above to a different one in a different
            //col same row
			matrix[rows - 1 - j][i] = matrix[rows - 1 - i][rows - 1 - j];
            //set that one that you used to set above to the transpose
			matrix[rows - 1 - i][rows - 1 - j] = matrix[j][rows - 1 - i];
            //set this to the beginning cell value you were at
			matrix[j][rows - 1 - i] = tmp;
		}
	}
    }
};
