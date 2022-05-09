class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0) {
            return image;
        }
        fillMe(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    void fillMe (vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc] == newColor || image[sr][sc] != oldColor) {
            return;
        }
        image[sr][sc] = newColor;
        fillMe(image,sr+1,sc,oldColor,newColor);
        fillMe(image,sr,sc+1,oldColor,newColor);
        fillMe(image,sr-1,sc,oldColor,newColor);
        fillMe(image,sr,sc-1,oldColor,newColor);
    }
};
