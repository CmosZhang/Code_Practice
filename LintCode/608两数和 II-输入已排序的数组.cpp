#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//608. 两数和 II-输入已排序的数组
//您的提交打败了 36.40% 的提交!
vector<int> twoSum(vector<int> &nums, int target) {
	// write your code here
	if (nums.empty()) {
		return nums;
	}
	vector<int> res;
	int left = 0;
	int right = nums.size() - 1;
	while (left < right) {
		if (nums[left] + nums[right] < target) {
			left++;
		}
		else if (nums[left] + nums[right] > target) {
			right--;
		}
		else {
			res.push_back(left + 1);
			res.push_back(right + 1);
			return res;
		}
	}
	res.push_back(-1);
	res.push_back(-1);
	return res;
}