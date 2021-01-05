#include <algorithm>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
	int maxNum = 0;
	int curNum =0;
	for(auto elem : nums) {
		if(elem){
			curNum++;
		} else {
			maxNum = std::max(maxNum, curNum);
			curNum = 0;
		}
	}
	return std::max(maxNum, curNum);
}