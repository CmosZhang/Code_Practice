#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;


//47. 主元素 II
//您的提交打败了 30.80% 的提交!
//使用哈希表空间复杂度O(n),时间复杂度为O(n);
//int majorityNumber(vector<int> &nums) {
//	// write your code here
//	//用哈希表
//	int n = nums.size();
//	unordered_map<int, int>result;
//	for (int i = 0; i<n; i++)
//	{
//		if (++result[nums[i]]>n / 3)
//			return nums[i];
//	}
//	return -1;
//}



int partition(vector<int>&a, int left, int right)
{
	int temp = a[left];
	while (right > left)
	{
		while (left < right&&a[right] >= temp)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right&&a[left] <= temp)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[right] = temp;
	return left;
}


void quicksort(vector<int>&a, int left, int right)
{
	if (left < right)
	{
		int pos = partition(a, left, right);
		quicksort(a, left, pos - 1);
		quicksort(a, pos + 1, right);
	}
}

//使用快排算法来做的话，时间复杂度为O(nlgn)
//您的提交打败了 82.80% 的提交!
//int majorityNumber(vector<int> &nums) {
//	// write your code here
//	if (nums.empty())
//	{
//		return 0;
//	}
//	int len = nums.size();
//	sort(nums.begin(), nums.end());//使用排序算法
//	int count = 1;
//	for (int i = 0; i < len - 1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			count++;
//			if (count > nums.size() / 3)
//				return nums[i];
//		}
//		else
//		{
//			count = 1;
//		}
//	}
//}


//优秀算法
//使用枚举算法
//算法的时间复杂度为O(n),空间复杂度O(1),这也是题目要求
//您的提交打败了 44.40% 的提交!
int majorityNumber(vector<int> &nums) {
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	int candidate1, candidate2;
	int count1, count2;
	count1 = count2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (candidate1 == nums[i])
		{
			count1++;
		}
		else if (candidate2 == nums[i])
		{
			count2++;
		}
		else if (count1 == 0)
		{
			candidate1 = nums[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			candidate2 = nums[i];
			count2 = 1;
		}
		else
		{
			count1--;
			count2--;
		}
	}
	count1 = count2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == candidate1)
		{
			count1++;
		}
		else if (nums[i] == candidate2)
		{
			count2++;
		}
	}
	return count1 > count2 ? candidate1 : candidate2;
}
