#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//1236. 查找数组中没有出现的所有数字
//有额外空间的话，空间复杂度为O(n)，时间复杂度为O(n)
//您的提交打败了 62.95% 的提交!
vector<int> findDisappearedNumbers(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return nums;
	}
	int len = nums.size();
	vector<int> res;
	vector<int> temp(len + 1, 0);
	//类似于哈希的思想，统计出现的数
	for (int i = 0; i < len; i++) {
		temp[nums[i]] = 1;
	}
	for (int i = 0; i < len; i++) {
		if (temp[i + 1] == 0) {
			res.push_back(i + 1);
		}
	}
	return res;
}

//不适用额外的空间复杂度
//您的提交打败了 58.48% 的提交!
vector<int> findDisappearedNumbers2(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return nums;
	}
	int len = nums.size();
	vector<int> res;
	for (int i = 0; i < len; i++) {
		while (nums[i] != 0 && nums[i] != i + 1) {
			int idx = nums[i] - 1;
			if (nums[idx] == nums[i]) {
				nums[i] = 0;
			}
			else {
				swap(nums[idx], nums[i]);
			}
		}
	}
	
	for (int i = 0; i < len; i++) {
		if (nums[i] != i + 1) {
			res.push_back(i + 1);
		}
	}
	return res;
}

int main() {
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> res = findDisappearedNumbers2(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}