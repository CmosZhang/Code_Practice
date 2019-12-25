#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//1272.有序矩阵中的第K小元素
//不考虑时间和空间复杂度
int kthSmallest(vector<vector<int>> &matrix, int k) {
	// write your code here
	if (matrix.empty() || matrix[0].empty()) {
		return -1;
	}
	int n = matrix.size();
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr.push_back(matrix[i][j]);
		}
	}
	sort(arr.begin(), arr.end());
	return arr[k - 1];
}

//第二种方法
//使用二分法
int GetCount(vector<vector<int>>&matrix, int target) {
	int n = matrix.size();
	int i = n - 1;
	int j = 0;
	int ans = 0;
	while (i >= 0 && j < n) {
		if (matrix[i][j] <= target) {
			ans += i + 1;
			j++;
		}
		else {
			i--;
		}
	}
	return ans;
}
int kthSmallest2(vector<vector<int>> &matrix, int k) {
	// write your code here
	if (matrix.empty() || matrix[0].empty()) {
		return -1;
	}
	int n = matrix.size();
	int end = matrix[n - 1][n - 1];
	int start = matrix[0][0];
	while (start < end) {
		int mid = start + (end - start) / 2;
		int count = GetCount(matrix, mid);
		if (count < k) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}