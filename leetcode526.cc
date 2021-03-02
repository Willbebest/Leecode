class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int i=nums.size()-2;
        while(i>=0) {
            result += nums[i];
            i -=2 ; 
        }
        return result;
    }
};