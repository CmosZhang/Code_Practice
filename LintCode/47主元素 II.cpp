#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;


//47. ��Ԫ�� II
//�����ύ����� 30.80% ���ύ!
//ʹ�ù�ϣ��ռ临�Ӷ�O(n),ʱ�临�Ӷ�ΪO(n);
//int majorityNumber(vector<int> &nums) {
//	// write your code here
//	//�ù�ϣ��
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

//ʹ�ÿ����㷨�����Ļ���ʱ�临�Ӷ�ΪO(nlgn)
//�����ύ����� 82.80% ���ύ!
//int majorityNumber(vector<int> &nums) {
//	// write your code here
//	if (nums.empty())
//	{
//		return 0;
//	}
//	int len = nums.size();
//	sort(nums.begin(), nums.end());//ʹ�������㷨
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


//�����㷨
//ʹ��ö���㷨
//�㷨��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�O(1),��Ҳ����ĿҪ��
//�����ύ����� 44.40% ���ύ!
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