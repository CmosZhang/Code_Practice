#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1424. 数组中的最长山脉
//您的提交打败了 100.00% 的提交!
//
int longestMountain(vector<int> &A) {
	// write your code here
	if (A.empty() || A.size() < 3) {
		return 0;
	}
	int len = A.size();
	int left = 0;
	int right = 0;
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (right > 0 && A[i - 1] < A[i] || A[i - 1] == A[i]) {
			left = 0;
			right = 0;
		}
		if (A[i - 1] < A[i]) {
			left++;
		}
		if (A[i - 1] > A[i]) {
			right++;
		}
		if (left > 0 && right > 0 && right + left + 1 > res) {
			res = left + right + 1;
		}
	}
	return res;
}


//优秀的答案
//上述方法比较难理解，使用动态规划的方法
//思路分析：我们只要从左到右确定以A[i]为尾端的最长递增子数组，
//以A[i]为开始的最长递减子数组
//两个合并就是一个山脉
//您的提交打败了 100.00% 的提交!
int longestMountain2(vector<int> &A) {
	// write your code here
	if (A.empty() || A.size() < 3) {
		return 0;
	}
	int len = A.size();
	//left[i]记录以A[i]为结尾的最长递增子数组
	vector<int> left(len, 1);
	//right[i]记录以A[i]为开始的最长递减子数组
	vector<int> right(len, 1);

	//从左往右：
	for (int i = 1; i < len; i++) {
		if (A[i - 1] < A[i]) {
			left[i] = left[i - 1] + 1;
		}
	}
	//从右往左：
	for (int i = len - 2; i >= 0; i--) {
		if (A[i] > A[i + 1]) {
			right[i] = right[i + 1] + 1;
		}
	}

	//合并
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (left[i] > 1 && right[i] > 1) {
			res = max(res, left[i] + right[i] - 1);//中间的山顶计算了两次
		}
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
	cout << longestMountain2(nums) << endl;
	system("pause");
	return 0;
}