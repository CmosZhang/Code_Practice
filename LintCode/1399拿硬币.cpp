#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//1399. 拿硬币
//贪心的思路
//本题陷阱：不能按照贪心来取，也就是不能每次取的时候都比较当前的前后两个值取其大者。       
//例[1, 9999, 3, 4, 5], 当K = 2时，如果按照贪心，取到的就是5, 4， 发生错误。       
//需要把所有的情况都遍历一遍，才能确定最大和的情况。
//以下代码采用贪心的思路导致结果错误。
//int takeCoins(vector<int> &list, int k) {
//	// Write your code here
//	if (list.empty() || k == 0) {
//		return 0;
//	}
//	int res = 0;
//	int count = 1;
//	int len = list.size();
//	int left = 0;
//	int right = len - 1;
//	while (count <= k) {
//		int left_temp = left;
//		int right_temp = right;
//		if (list[left_temp] >= list[right_temp]) {
//			left++;
//			res += list[left_temp];
//		}
//		else {
//			right--;
//			res += list[right_temp];
//		}
//		count++;
//	}
//	return res;
//}

//您的提交打败了 95.36% 的提交!
//本题是只能从最左边或者右边拿k次，可以进行k次遍历，开始k次都从最左边拿，
//然后是从左边拿k-1个，从右边拿1个......一直到全部k个都是从右边拿，
//在此过程中，利用一个变量保存最大和的情况。
int takeCoins(vector<int> &list, int k) {
	// Write your code here
	if (list.empty() || k <= 0) {
		return 0;
	}
	int res = 0;
	int add = 0;
	for (int i = 0; i < k; i++) {
		add += list[i];
	}
	res = max(add, res);
	int idx = k - 1;
	int right = list.size() - 1;
	while (idx >= 0) {
		add -= list[idx];
		add += list[right];
		res = max(add, res);
		idx--;
		right--;
	}
	return res;
}

int main() {
	vector<int> nums = { 5,4,3,2,1 };
	int k = 2;
	cout << takeCoins(nums, k) << endl;
	system("pause");
	return 0;
}