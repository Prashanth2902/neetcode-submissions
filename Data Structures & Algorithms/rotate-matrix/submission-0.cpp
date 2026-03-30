class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        reverse(matrix.begin(), matrix.end());

        for(int r=0;r<rows;r++) {
            for(int c=r+1;c<cols;c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};
