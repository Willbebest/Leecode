class Solution {
public:
    //分别使用两个set标记有零的行和列
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for(int i=0; i< matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto elem : rows) {
            for(int i=0; i< matrix[0].size(); i++) {
                matrix[elem][i] =0;
            }
        }
        for(auto elem : cols) {
            for(int j = 0; j<matrix.size(); j++) {
                matrix[j][elem] =0;
            }
        }
    }
};