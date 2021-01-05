int thirdMax(vector<int>& nums) {
    long firstMax = LONG_MIN;
    long secondMax = LONG_MIN;
    long thirdMax = LONG_MIN;
    for(auto elem : nums) {
        if(elem > firstMax) {
            thirdMax =secondMax;
            secondMax = firstMax;
            firstMax = elem;
        } else if(elem > secondMax && firstMax > elem) {
            thirdMax = secondMax;
            secondMax = elem;
        } else if(elem > thirdMax && secondMax > elem) {
            thirdMax = elem;
        }
    }
    return thirdMax == LONG_MIN ? firstMax : thirdMax;
}
