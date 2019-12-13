#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1297. 比自己小的元素个数
//最容易想到的是暴力求解方法
//时间复杂度为O(n^2)，运行时会超时
//通过91%的数据
vector<int> countSmaller(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return nums;
	}
	int n = nums.size();
	vector<int> res(n, 0);
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[i]) {
				count++;
			}
		}
		res[i] = count;
	}
	return res;
}


//第二种方法
//使用记忆化排序的方式来做
//您的提交打败了 98.83% 的提交!
const int MAXN = 100007;
int cnt[MAXN], n;

struct Node {
	int num;
	int index;
};

static bool Compare(Node &a, Node &b) {
	return a.num < b.num;
}

inline void add(int k){
	for (; k <= n; k += -k & k) cnt[k] += 1;
}

int sum(int k){
	int res = 0;
	for (; k; k -= -k & k) res += cnt[k];
	return res;
}

//以下代码有点小问题
//vector<int> countSmaller2(vector<int> &nums) {
//	 write your code here
//	if (nums.empty()) {
//		return nums;
//	}
//	int n = nums.size();
//	vector<int> res(n);
//	vector<Node> A(n);
//	/*建立一个从数组内容到未排序前索引的映射A*/
//	for (int i = 0; i < n; i++) {
//		A[i].num = nums[i];
//		A[i].index = i + 1;
//	}
//	memset(cnt, 0, sizeof(cnt));
//	sort(A.begin(), A.end(), Compare);//使用快排思想
//
//	for (int i = 0; i < n; i++) {
//		int idx = A[i].index;
//		int t = sum(n) - sum(idx);
//		res[idx - 1] = t;
//		add(idx);
//	}
//	return res;
//}

vector<int> countSmaller2(vector<int>& nums) {
	n = nums.size();
	vector<int> ans(n, 0);
	vector<pair<int, int>> A;
	/*建立一个从数组内容到未排序前索引的映射A*/
	for (int i = 0; i < n; i++) {
		A.push_back({ nums[i], i + 1 });
	}
	memset(cnt, 0, sizeof(cnt));
	sort(A.begin(), A.end());
	/*进行排序*/
	for (int i = 0; i < n; i++) {
		int id = A[i].second;
		int t = sum(n) - sum(id);
		ans[id - 1] = t;
		add(id);
	}
	return ans;
}


//第3种方法
//使用我们看到每次我们都要从末尾遍历相同的元素，实际上我们可以建立一个保持排序的数组sorted_num。
//这个数组代表：在nums[i]之后所有的数，并且已经排好序。
//每次在nums数组出现新的需要判断的数就要插入到这个sorted_num，
//然后在这个数通过二分查找到下界(可以用STL自带的lower_bound()) 减去sorted_num.begin()就是比nums[i]小的元素个数了。
//您的提交打败了 42.80% 的提交!
//vector<int> countSmaller3(vector<int>& nums) {
//	vector<int> sorted_num;
//	/*建立一个保持排序的数组*/
//	vector<int> res;
//	/*用于保存结果的数组*/
//	for (int i = nums.size() - 1; i >= 0; i--) {
//		auto iter = lower_bound(sorted_num.begin(), sorted_num.end(), nums[i]);
//		/*通过lower_bound()二分寻找下界，返回一个迭代器(也就是相对于sorted_num的index)*/
//		int pos = iter - sorted_num.begin();
//		/*
//		通过排序数组的二分查找性质，我们可以知道iter-sorted_num.begin()(可以理解成sorted_num数组的起始位置)就是
//		题目需要的比nums[i]小的数字个数
//		*/
//		sorted_num.insert(iter, nums[i]);
//		/*这时nums[i]已经使用完了，需要给以后的数字拿来判断
//		插入后要保持sorted_num排序，所以nums[i]插入到iter位置*/
//		res.push_back(pos);
//	}
//	reverse(res.begin(), res.end());
//	/*一路上都是倒序插入的，所以在最后要逆转数组*/
//	return res;
//}

vector<int> countSmaller3(vector<int>& nums) {
	vector<int>t, res(nums.size());
	/*初始化t,res*/
	for (int i = nums.size() - 1; i >= 0; i--) {
		int left = 0, right = t.size();
		/*下面是一个在t数组里二分查找的过程*/
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (t[mid] >= nums[i]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		res[i] = right;
		t.insert(t.begin() + right, nums[i]);
	}
	return res;
}


int main() {
	vector<int> nums = { 5,2,6,1 };
	vector<int> res = countSmaller2(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}