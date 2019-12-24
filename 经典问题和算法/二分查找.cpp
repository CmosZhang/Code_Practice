#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//经典的二分查找，任意匹配
int findPosition(vector<int> &nums, int target) {
	if (nums.size() <= 0) {
		return -1;
	}
	int len = nums.size();
	int low = 0, high = len - 1, mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


//目标位置最右匹配
int lastPosition(vector<int> &nums, int target) {
	// write your code here
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


//目标位置最左匹配
int firstPosition(vector<int> &nums, int target) {
	if (nums.empty()) {
		return -1;
	}
	int len = nums.size();
	int left = 0;
	int right = len - 1;
	while (left < right - 1) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target) {
			right = mid;
		}
		else{
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