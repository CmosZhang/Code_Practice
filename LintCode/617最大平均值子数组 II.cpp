#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


//617.最大平均值子数组 II
//您的提交打败了 32.60% 的提交!
double MaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	double l = INT_MAX, r = INT_MIN;
	for (int i = 0; i < n; i++) {
		l = min(l, (double)nums[i]);
		r = max(r, (double)nums[i]);
	}
	vector<double> sumNums(n + 1);
	sumNums[0] = 0;
	while (r - l > 1e-6) {
		double mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			sumNums[i + 1] = sumNums[i] + nums[i] - mid;
		}
		double preMin = 0;
		double sumMax = INT_MIN;
		for (int i = k; i <= n; i++) {
			sumMax = max(sumMax, sumNums[i] - preMin);
			preMin = min(preMin, sumNums[i - k + 1]);
		}
		if (sumMax >= 0) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return l;
}