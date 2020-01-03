#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//1040. 最大分块排序 II
//网上的优秀方法
//您的提交打败了 77.66% 的提交!
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

//不能使用单调栈来做，这是有问题的，例如例子 arr={1,3,2,5,4,4,7,6,6,8}

//方法二：
//思路：单调栈，单调不减。栈顶总是保存当前遇到的最大的数，如果遇到一个比栈顶小的元素，则记录栈顶元素，
//将栈中小于该元素的值全部弹出（意味着这些值应该分到一个块里面去）
//最后将记录的栈顶值重新压回栈中，代表当前块中的最大值
//您的提交打败了 77.66% 的提交!
//这个答案有问题啊
//int maxChunksToSorted2(vector<int> &arr) {
//	if (arr.empty()) {
//		return -1;
//	}
//	int len = arr.size();
//	stack<int> stk;
//	stk.push(arr[0]);
//	for (int i = 1; i < len; i++) {
//		if (arr[i] >= stk.top()) {
//			stk.push(arr[i]);
//		}
//		else {
//			int temp = stk.top();
//			stk.pop();
//			while (!stk.empty() && stk.top() < temp) {
//				stk.pop();
//			}
//			stk.push(temp);
//		}
//	}
//	return stk.size();
//}

////通过40%的数据
//int maxChunksToSorted3(vector<int> &arr) {
//	// write your code here
//	if (arr.empty()) {
//		return -1;
//	}
//	int len = arr.size();
//	stack<int> stk;
//	stack<int> help;
//	stk.push(arr[0]);
//	for (int i = 1; i < len; i++) {
//		if (arr[i] > stk.top()) {
//			stk.push(arr[i]);
//		}
//		else {
//			int temp = stk.top();
//			stk.pop();
//			while (!stk.empty()) {
//				help.push(stk.top());
//				stk.pop();
//			}
//			while (!help.empty()) {
//				if (help.top() >= temp) {
//					stk.push(help.top());
//				}
//				help.pop();
//			}
//			stk.push(temp);
//		}
//	}
//	return stk.size();
//}



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
	cout << maxChunksToSorted(num) << endl;
	system("pause");
	return 0;
}