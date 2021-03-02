class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        for(int i=0; i<matrix.size(); i++){
            vector<int> sum;
            sum.push_back(matrix[i][0]);
            for(int j=1; j<matrix[i].size(); j++) {
                sum.push_back(sum[j-1]+matrix[i][j]);
            }
            m_sums.push_back(sum);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result =0;
        for(int i=row1; i <= row2; i++) {
            if(col1==0)
                result += m_sums[i][col2];
            else
                result += m_sums[i][col2] - m_sums[i][col1-1];
        }
        return result;
    }
private:
    vector<vector<int>> m_sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */