#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//159. 寻找旋转排序数组中的最小值
//二分查找的思想，数组当中没有重复的元素。
int findMin(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return -1;
	}
	int l = nums.size();
	int low = 0, high = l - 1, mid;
	if (nums.size() == 1)
	{
		return nums[0];
	}
	//数组序列本来就是升序
	if (nums[low] < nums[high])
	{
		return nums[low];
	}
	//数组序列本来就是降序
	if (nums[high] < nums[high - 1])
	{
		return nums[high];
	}
	//数组顺序被打乱，成为旋转排序
	while (low < high)
	{
		mid = (low + high) / 2;
		if (nums[mid] > nums[high])
			low = mid + 1;
		else
			high = mid;
	}
	return nums[low];
}


//160. 寻找旋转排序数组中的最小值 II
//直接暴力求解，打败97%的提交。没用任何技巧。
 int findMinII(vector<int> &nums)
 {
        // write your code here
    if(nums.size()<=0)
    {
        return -1;
    }
    if (nums.size() == 1)
	{
		return nums[0];
	}
	int l = nums.size();
	int low = 0, high = l - 1, mid;
	//数组序列本来就是升序
	if (nums[low] < nums[high])
	{
		return nums[low];
	}
	int min = nums[0];
	for(int i=0;i<l;i++)
	{
	    if(min>nums[i])
	    {
	        min = nums[i];
	    }
	}
	return min;
}



int main()
{
	vector<int> nums = { 4,5,6,6,7,0,1,2,2,2};
	int res = findMinII(nums);
	cout << res << endl;
	system("pause");
	return 1;
}