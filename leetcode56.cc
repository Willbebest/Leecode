class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> left, vector<int> right)
            { return left[0]<right[0];});
        int startInterVal = intervals[0][0];
        int endInterVal = intervals[0][1];
        for(auto elem :intervals) {
            if(endInterVal >= elem[0]) 
                endInterVal = (endInterVal > elem[1] ? endInterVal:elem[1]);
            else {
                result.push_back({startInterVal, endInterVal});
                startInterVal = elem[0];
                endInterVal = elem[1];
            }
        }
        result.push_back({startInterVal, endInterVal});
        return result;
    }
};