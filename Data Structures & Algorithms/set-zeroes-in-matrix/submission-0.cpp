class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowzero;
        unordered_set<int> colzero;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == 0) {
                    rowzero.insert(i);
                    colzero.insert(j);
                }
            }
        }

        for(auto n: rowzero) {
            for(int j=0;j<matrix[0].size();j++) {
                matrix[n][j] = 0;
            }
        }

        for(auto n: colzero) {
            for(int j=0;j<matrix.size();j++) {
                matrix[j][n] = 0;
            }
        }
    }
};
