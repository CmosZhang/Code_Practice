#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


//544. 前K大数
//
//vector<int> topk(vector<int> &nums, int k)
//{
//	// write your code here
//	vector<int>res;
//	if(nums.size()<=0||k<=0)
//	{
//	   return res;
//	}
//	sort(nums.begin(),nums.end());
//	int len=nums.size();
//	for(int i=0;i<k;i++)
//	{
//	res.push_back(nums[len-1-i]);
//	}
//}


//利用优先级队列
//您的提交打败了 81.60% 的提交!
vector<int> topk(vector<int> &nums, int k)
{
	vector<int>res;
	if (nums.size() <= 0 || k <= 0)
	{
		return res;
	}
	priority_queue<int> temp(nums.begin(), nums.end());

	while (!temp.empty() && res.size() < k)
	{
		res.push_back(temp.top());
		temp.pop();
	}
	return res;
}


//使用最小堆来实现取前K大数
//您的提交打败了 54.20% 的提交!
vector<int> topk(vector<int> &nums, int k)
{
	vector<int>res;
	if (nums.size() <= 0 || k <= 0)
	{
		return res;
	}
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i < k)
		{
			minHeap.push(nums[i]);
		}
		else
		{
			if (nums[i] <= minHeap.top())
			{
				continue;
			}
			else
			{
				minHeap.pop();
				minHeap.push(nums[i]);
			}
		}
	}
	while (!minHeap.empty()) 
	{   //输出最大的K个数
		res.push_back(minHeap.top());
		minHeap.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}


//使用最大堆来实现取前K小数
vector<int> mintopk(vector<int> &nums, int k)
{
	vector<int>res;
	if (nums.size() <= 0 || k <= 0)  //注意k>nums.size()的处理方式
	{
		return res;
	}
	priority_queue<int, vector<int>, less<int>> maxHeap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i < k)
		{
			maxHeap.push(nums[i]);
		}
		else
		{
			if (nums[i] >= maxHeap.top())
			{
				continue;
			}
			else
			{
				maxHeap.pop();
				maxHeap.push(nums[i]);
			}
		}
	}
	while (!maxHeap.empty())
	{   //输出最大的K个数
		res.push_back(maxHeap.top());
		maxHeap.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}


//使用快排的思想来做前K大数
int Partition(vector<int>&arr, int left, int right)
{
	int temp = arr[left];
	while (left < right)
	{
		while (left < right&&arr[right] >= temp)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right&&arr[left] <= temp)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[right] = temp;
	return left;
}


int getPartition(vector<int> &input, int start, int end)
{ 
	if (input.empty() || start > end) 
		return -1;       
	int temp = input[end];  
	int j = start - 1;    
	for (int i = start; i < end; ++i) 
	{ 
		if (input[i] <= temp) 
		{
			++j;  
			if (i != j) 
				swap(input[i], input[j]);
		}
	}        
	swap(input[j + 1], input[end]);  
	return (j + 1); 
}

vector<int> mintopk2(vector<int> &nums, int k)
{
	if (nums.size() <= 0 || k <= 0)  //注意k>nums.size()的处理方式
	{
		return vector<int>();
	}
	int left = 0;
	int right = nums.size() - 1;
	int index = getPartition(nums, left, right);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			right = index - 1;
			index = getPartition(nums, left, right);
		}
		else
		{
			left = index + 1;
			index = getPartition(nums, left, right);
		}
	}
	vector<int> res(nums.end() - k, nums.end());
	reverse(res.begin(), res.end());
	return res;
}
