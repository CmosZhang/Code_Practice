#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//402. 连续子数组求和
//您的提交打败了 100.00% 的提交!
vector<int> continuousSubarraySum(vector<int> &A) {
	// write your code here
	if (A.empty()) {
		return A;
	}
	int len = A.size();vecto
	vector<int> dp(len);
	vector<int> res;
	res.push_back(0);
	res.push_back(0);
	int n = A.size();
	int res_sum = A[0]; // 当前答案区间的和
	int sum = 0;        // 枚举过程中区间的和
	int l = 0;          // 枚举过程中区间左端点
	for (int r = 0; r < n; r++)
	{
		if (sum < 0)    // 如果前面连续区间的和小于0, 那么以r为右端点的最大和就是 A[r]
		{
			l = r;
			sum = A[r];
		}
		else
			sum += A[r];
		if (sum > res_sum)  // 更新答案区间: 如果当前区间和大于答案区间
		{
			res_sum = sum;
			res[0] = l;
			res[1] = r;
		}
	}
	return res;
}