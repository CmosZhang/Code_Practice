#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//删除排序数组中重复数字
int removeDuplicates(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int j = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i-1])
		{
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}


//101删除排序数组中的重复数字 II
int removeDuplicates2(vector<int> &nums)
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int j = 2;
	int nums_len = nums.size();
	while (j < nums_len)
	{
		if (nums[j] == nums[j - 2])
		{
			nums.erase(nums.begin()+j);
			nums_len -= 1;
		}
		else
			j += 1;		
	}
	return nums_len;


	//for (int i = 2; i<nums.size(); i++)
	//{
	//	if (nums[i] != nums[i - 2])
	//	{
	//		nums[j] = nums[i];
	//		j++;
	//	}
	//}
	//return j;
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 7; i++)
	{
		vec.push_back(i);
	}
	//vec.push_back(4);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(4);
	sort(vec.begin(), vec.end());
	int res = removeDuplicates2(vec);
	cout << res << endl;
	system("pause");
	return 1;
}