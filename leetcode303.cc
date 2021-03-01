class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(!nums.empty()) {
            sums.push_back(nums[0]);
            for(int i=1; i< nums.size(); i++) {
                sums.push_back(sums[i-1] + nums[i]);
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i>=sums.size() || j>= sums.size() || i>j ){
            return 0;
        }
        if(i==0) 
            return sums[j];
        else
            return sums[j]-sums[i-1];
    }
private:
    vector<int> sums;
};