#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

//数组中只有唯一的主元素
//hash的方法是最容易想到的算法
//48. 主元素 III
//您的提交打败了 48.40% 的提交!
//使用哈希：时间复杂度O(n)，空间复杂度O(n);
//int majorityNumber(vector<int> &nums, int k) {
//	// write your code here
//	int n = nums.size();
//	unordered_map<int, int>result;
//	for (int i = 0; i<n; i++)
//	{
//		if (++result[nums[i]]>n / k)
//			return nums[i];
//	}
//	return -1;
//}


//优秀算法：
//题目的要求为空间复杂度为O(k),时间复杂度为O(n);
//在上述两题的基础上发展而来
//这个算法的时间复杂度为O(nk+k-1+n*(k-1)+k-1)=O(2nk+2(k-1)),当n>>k时，算法的时间复杂度为O(nk),也就近似O(n);
//这个算法在n>>k的情况下，优势比较明显
//您的提交打败了 83.80% 的提交!
int majorityNumber(vector<int> &nums, int k) {
	// write your code here
	if (nums.empty())
	{
		return -1;
	}
	int len = nums.size();
	vector<int> MajorNum(k - 1, 0);//两个数组，空间复杂度为O(2*(k-1))
	vector<int> count(k - 1, 0);
	bool hasused = false;

	//整个循环的算法的时间复杂度为O(n*((k-1)+(k-1)+(k-1))=O(3n(k-1))=O(nk)
	for (int i = 0; i < len; i++)
	{
		hasused = false;
		for (int j = 0; j < k - 1; j++) //这块程序刚开始因为major元素全为0，是要整个遍历一变的。
		{
			if (MajorNum[j] == nums[i])
			{
				count[j]++;
				hasused = true;
				break; //跳出的是for循环
			}
		}

		if (hasused)
		{
			continue;
		}

		//时间复杂度：刚开始因为count元素全为0，只运行一次，
		//随着数据的增多，复杂度变为O(k-1)
		for (int j = 0; j < k - 1; j++) 
		{
			if (count[j] == 0)
			{
				MajorNum[j] = nums[i];
				count[j]++;
				hasused = true;
				break;
			}
		}

		if (hasused)
		{
			continue;
		}

		for (int j = 0; j < k - 1; j++)//时间复杂度O(k-1)
		{
			if (count[j] != 0)
			{
				count[j]--;
			}
		}
	}

	//这个模块的时间复杂度为O(k-1)
	for (int j = 0; j < k - 1; j++)
	{
		count[j] = 0;
	}

	//这一个模块的时间复杂度为O(n*(k-1))
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (MajorNum[j] == nums[i])
			{
				count[j]++;
			}
		}
	}

	//这个模块的时间复杂度为O(k-1)
	int index = 0;
	int temp = 0;
	for (int i = 0; i < k - 1; i++)
	{
		if (temp < count[i])
		{
			temp = count[i];
			index = i;
		}
	}
	return MajorNum[index];
}