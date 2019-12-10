#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//1212. 最大连续1的个数
//您的提交打败了 26.76% 的提交!
int findMaxConsecutiveOnes(vector<int> &nums) {
	// Write your code here
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			count++;
			res = max(count, res);
		}
		else {
			count = 0;
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
	cout << findMaxConsecutiveOnes(nums) << endl;
	system("pause");
	return 0;
}