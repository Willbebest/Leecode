class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0, currentSum = 0;
        for(auto elem : nums) {
            sum += elem;
        }
        for(int i = 0; i <= nums.size() - 1 ; i++) {
            if(currentSum * 2 == sum-nums[i]) {
                return i;
            }
            currentSum += nums[i];
        }
        return -1;
    }
};