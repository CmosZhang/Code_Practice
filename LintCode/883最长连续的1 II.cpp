#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//883. 最长连续的1 II
//您的提交打败了 100.00% 的提交!
//但这不是最简单的方法
//时间复杂度为O(n^2)
int findMaxConsecutiveOnes(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	int count = 0;//统计0之前存在1的个数
	int temp = 0;//统计0之后存在1的个数
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			count++;
		}
		else {
			temp = 0;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == 0) {
					break;
				}
				else {
					temp++;
				}
			}
			res = max(count + temp + 1, res);
			count = 0;
		}
		if (i == nums.size() - 1) {
			res = max(res, count);
		}
	}
	return res;
}

//网上的优秀答案
//使用动态规划的思想来做
int findMaxConsecutiveOnes2(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	int countZero = 0;//包含反转0操作1的长度
	int countNotZero = 0;//不包含反转0操作1的长度
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			countNotZero++;
			countZero++;
		}
		else {
			countZero = countNotZero + 1;
			countNotZero = 0;
		}
		res = max(res, max(countNotZero, countZero));
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
	cout << findMaxConsecutiveOnes2(nums) << endl;
	system("pause");
	return 0;
}