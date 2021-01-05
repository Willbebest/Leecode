// 答案一
int maximumProduct(vector<int>& nums) {
    int64_t firstMax = INT_MIN;
    int64_t secondMax = INT_MIN;
    int64_t thirdMax = INT_MIN;
    int64_t firstMin = INT_MAX;
    int64_t secondMin = INT_MAX;

    for(auto elem : nums) {
        if(elem > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = elem;
        } else if(elem > secondMax) {
            thirdMax = secondMax;
            secondMax = elem;
        } else if(elem > thirdMax) {
            thirdMax = elem;
        } 
        if(elem < firstMin){
            secondMin = firstMin;
            firstMin = elem;
        } else if(elem < secondMin) {
            secondMin = elem;
        }
    }

    return max(firstMin*secondMin*firstMax, firstMax*secondMax*thirdMax);
}

// 答案二
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int64_t sum1 = nums[0] * nums[1] * nums.back();
    size_t len = nums.size();
    int64_t sum2 = nums[len-1] * nums[len-2] * nums[len-3];
    return max(sum2, sum1); 
}