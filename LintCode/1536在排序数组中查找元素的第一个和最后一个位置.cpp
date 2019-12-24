#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;



//1536. 在排序数组中查找元素的第一个和最后一个位置
//您的提交打败了 93.23% 的提交!
int lastPosition(vector<int> &nums, int target) {
	if (nums.empty()) {
		return -1;
	}
	int len = nums.size();
	int left = 0;
	int right = len - 1;
	while (left < right - 1) {
		int mid = left + (right - left) / 2;
		if (nums[mid] <= target) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	if (nums[right] == target) {
		return right;
	}
	if (nums[left] == target) {
		return left;
	}
	return -1;
}


//最左匹配
int firstPosition(vector<int> &nums, int target) {
	if (nums.empty()) {
		return -1;
	}
	int len = nums.size();
	int left = 0;
	int right = len - 1;
	while (left < right - 1) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			right = mid;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid;
		}
	}
	if (nums[left] == target) {
		return left;
	}
	if (nums[right] == target) {
		return right;
	}
	return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
	// Write your code here.
	if (nums.empty()) {
		return nums;
	}
	vector<int> res;
	int first = firstPosition(nums, target);
	int last = lastPosition(nums, target);
	res.push_back(first);
	res.push_back(last);
	return res;
}