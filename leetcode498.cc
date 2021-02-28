class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // 通过和去寻找
        if(matrix.empty()) return {};
        vector<int> result;
        int xSize = matrix.size();
        int ySize = matrix[0].size();
        for(int i=0; i <= xSize+ySize-2; i++) {
            for( int j=0; j <= i; j++) {
                int x = j;
                int y= i - j;
                if(i%2==0) swap(x,y);
                if(x>=xSize || y>= ySize) continue;
                result.push_back(matrix[x][y]);
            }
        }
        return result;
    }
};