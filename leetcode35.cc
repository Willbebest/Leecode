class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size()) {
            if(target == nums[i]) return i;
            else if(target<nums[i]) break;
            else i++;
        }
        nums.insert(i+nums.begin(), target);
        return i;
    }
};