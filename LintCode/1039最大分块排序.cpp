#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1039. 最大分块排序
//您的提交打败了 64.75% 的提交!
//优秀的方法
int maxChunksToSorted(vector<int> &arr) {
	// write your code here
	if (arr.empty()) {
		return -1;
	}
	int len = arr.size();
	vector<int> maxOfLeft(len);
	vector<int> minOfRight(len);

	maxOfLeft[0] = arr[0];
	for (int i = 1; i < len; i++) {
		maxOfLeft[i] = max(maxOfLeft[i - 1], arr[i]);
	}

	minOfRight[len - 1] = arr[len - 1];
	for (int i = len - 2; i >= 0; i--) {
		minOfRight[i] = min(minOfRight[i + 1], arr[i]);
	}

	int res = 0;
	for (int i = 0; i < len - 1; i++) {
		if (maxOfLeft[i] <= minOfRight[i + 1])
			res++;
	}
	return res + 1;
}

//第二种方法：这个是数组比较特殊，数组中的最大值小于数组的长度
//思路：
//只需要判断，当前的最大值是不是跟index相等。
//如果相等，说明这段区间已经具备了所有元素。
//如果不相等，说明该区间装不下当前最大值，区间应该扩张。
//您的提交打败了 54.92% 的提交!
int maxChunksToSorted2(vector<int> &arr) {
	// write your code here
	if (arr.empty()) {
		return -1;
	}
	int len = arr.size();
	int res = 0;
	int maxValue = arr[0];
	for (int i = 0; i < len; i++) {
		maxValue = max(maxValue, arr[i]);
		if (maxValue == i) {
			res++;
		}
	}
	return res;
}

int main() {
	vector<int> num;
	while (1) {
		int temp;
		cin >> temp;
		num.push_back(temp);
		char c;
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	cout << maxChunksToSorted2(num) << endl;
	system("pause");
	return 0;
}
