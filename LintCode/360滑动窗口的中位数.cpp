#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>

using namespace std;

//360. 滑动窗口的中位数
//是用最笨的方法来做，遍历求解，算法的时间复杂度太高，O(nk*klogk)
//vector<int> medianSlidingWindow(vector<int> &nums, int k) 
//{
//	// write your code here
//	vector<int> res;
//	if (nums.empty() || k <= 0)
//	{
//		return res;
//	}
//	for (int i = 0; i < nums.size() - k; i++)
//	{
//		vector<int> temp;
//		for (int j = 0; j < k; j++)
//		{
//			temp.push_back(nums[j]);
//			sort(temp.begin(), temp.end());
//			int median = temp[k / 2];
//			res.push_back(median);
//		}
//	}
//	return res;
//}


//方法二
//使用最大堆和最小堆来做
vector<int> medianSlidingWindow(vector<int> &nums, int k)
{
	if (nums.empty())
	{
		return nums;
	}
	vector<int> res;


}
vector<int> medianSlidingWindow(vector<int> &nums, int k) {
	// write your code here
	vector<int> result;
	int n = nums.size();
	if (n == 0)
		return result;

	multiset<int> max, min;
	for (int i = 0; i < k; ++i)
		max.insert(nums[i]);

	for (int i = 0; i < k / 2; ++i) {
		min.insert(*max.rbegin());
		max.erase(max.lower_bound(*max.rbegin()));
	}

	for (int i = k; i < n; ++i) {
		result.push_back(*max.rbegin());
		if (max.find(nums[i - k]) != max.end()) {
			max.erase(max.find(nums[i - k]));
			max.insert(nums[i]);
		}
		else {
			min.erase(min.find(nums[i - k]));
			min.insert(nums[i]);
		}
		if (max.size() > 0 && min.size() > 0 && *max.rbegin() > *min.begin()) {
			int tmp = *max.rbegin();
			max.erase(max.lower_bound(*max.rbegin()));
			max.insert(*min.begin());
			min.erase(min.begin());
			min.insert(tmp);
		}
	}
	result.push_back(*max.rbegin());
	return result;
}


int main()
{
	vector<int> nums = { 1,2,7,8,5 };
	int k = 3;
	vector<int> res = medianSlidingWindow(nums, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}