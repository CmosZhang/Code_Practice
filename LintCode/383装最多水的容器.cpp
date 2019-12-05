#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


//383. 装最多水的容器
//Time Limit Exceeded
//耗时太长
//int maxArea(vector<int> &heights)
//{
//	// write your code here
//	if (heights.empty())
//	{
//		return 0;
//	}
//	int maxarea = INT_MIN;
//	int len = heights.size();
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			int left = i + 1;
//			int right = j + 1;
//			int area = (right - left)*min(heights[i], heights[j]);
//			if (maxarea < area)
//			{
//				maxarea = area;
//			}
//		}
//	}
//	return maxarea;
//}
//您的提交打败了 98.60% 的提交!
int maxArea(vector<int> &heights)
{
	if (heights.empty())
	{
		return 0;
	}
	int len = heights.size();
	int left = 0;
	int right = len - 1;
	int area = 0;
	while (left < right)
	{
		area = max(area, min(heights[left], heights[right])*(right - left));
		if (heights[left] > heights[right])
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return area;
}

int main()
{
	vector<int> nums = { 1,2,3 };
	int res = maxArea(nums);
	cout << res << endl;
	system("pause");
	return 0;
}