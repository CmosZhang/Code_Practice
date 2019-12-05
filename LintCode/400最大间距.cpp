#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

//400. 最大间距
//您的提交打败了 75.40% 的提交!
//使用排序的方法来做很简单
/*
int maximumGap(vector<int> &nums)
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return 0;
	}
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int maxGap = INT_MIN;
	for (int i = 1; i < len; i++)
	{
		if (maxGap < nums[i] - nums[i - 1])
		{
			maxGap = nums[i] - nums[i - 1];
		}
	}
	return maxGap;
}
*/


//用线性的时间和空间复杂度的方法解决这个问题
//使用桶排序的方法
//您的提交打败了 75.80% 的提交!
int maximumGap(vector<int> &nums)
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return 0;
	}
	
	int len = nums.size();
	int minValue = INT_MAX, maxValue = INT_MIN;
	for (int i = 0; i<len; i++)
	{
		maxValue = max(maxValue, nums[i]);
		minValue = min(minValue, nums[i]);
	}

	
	int size = (maxValue - minValue) / len + 1;
	int bucket_nums = (maxValue - minValue) / size + 1;
	vector<int> bucketMax(bucket_nums, INT_MIN);
	vector<int> bucketMin(bucket_nums, INT_MAX);
	//桶内不排序，只保留两个数，一个最大值，一个最小值，这两个数不断更新。其他数一概不要
	//找到当前桶的最小值与前一个桶的最大值作比较即可
	set<int> s;
	for (int i = 0; i<len; i++) 
	{
		int idx = (nums[i] - minValue) / size;
		bucketMin[idx] = min(bucketMin[idx], nums[i]);
		bucketMax[idx] = max(bucketMax[idx], nums[i]);
		s.insert(idx);//在set中插入元素
	}
	int pre = 0;
	int maxGap = 0;
	for (int i = 1; i < len; ++i)
	{
		if (!s.count(i)) 
			continue;//查找键key的元素个数
		maxGap = max(maxGap, bucketMin[i] - bucketMax[pre]);
		pre = i;
	}
	return maxGap;
}

int main()
{
	vector<int> nums = { 3,2,1,4,3 };
	int res = maximumGap(nums);
	cout << res << endl;
	system("pause");
	return 0;

}