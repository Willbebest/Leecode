class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (x, y) ==> (y, n-x)
        vector<vector<int>> temp = matrix;
        for(int i=0; i< matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                matrix[j][matrix.size()-1-i] = temp[i][j];
            }
        }
    }
};