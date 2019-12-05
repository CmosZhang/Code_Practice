#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1075.乘积小于K的子数组
//使用暴力求解的方法，这不是最简单的方法
//您的提交打败了 100.00% 的提交!
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty()) {
		return 0;
	}
	int len = nums.size();
	
	int res = 0;
	for (int i = 0; i < len; i++) {
		int left = i;
		int right = len - 1;
		int mul = 1;
		while (left <= right) {
			mul = mul * nums[left];
			if (mul < k) {
				res++;
				left++;
			}
			else {
				break;
			}
		}
	}
	return res;
}

//优秀的答案
//时间复杂度为O(n)
//思路：
//维护一个滑动窗口，left为窗口的左端点，i用来探索下一个数，left和i组成的滑动窗口为[left, i]
//如果当前窗口中的所有数的乘积 >= k， 说明窗口不再满足条件( < k), 
//则把left指向的左端点的数从窗口中去掉，反映在窗口乘积上应该是除以要删除的这个数，
//然后left++，一直重复下去直到窗口再次满足条件，则又找到了一个新的窗口，
//窗口的长度就是当前窗口中满足条件的子数组个数，
//窗口长度用 i - left + 1来表示。

int numSubarrayProductLessThanK2(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty()) {
		return 0;
	}
	int len = nums.size();
	int res = 0;
	int left = 0;
	int product = 1;
	for (int i = 0; i < len; i++) {
		product *= nums[i];
		while (product >= k) {
			product /= nums[left++];
		}
		res += i - left + 1;
	}
	return res;
}

int main() {
	vector<int> nums;
	char c;
	int temp;
	while (1) {
		cin >> temp;
		nums.push_back(temp);
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	int k;
	cin >> k;
	cout << numSubarrayProductLessThanK2(nums, k) << endl;
	system("pause");
	return 0;
}