#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


//544. ǰK����
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


//�������ȼ�����
//�����ύ����� 81.60% ���ύ!
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


//ʹ����С����ʵ��ȡǰK����
//�����ύ����� 54.20% ���ύ!
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
	{   //�������K����
		res.push_back(minHeap.top());
		minHeap.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}


//ʹ��������ʵ��ȡǰKС��
vector<int> mintopk(vector<int> &nums, int k)
{
	vector<int>res;
	if (nums.size() <= 0 || k <= 0)  //ע��k>nums.size()�Ĵ���ʽ
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
	{   //�������K����
		res.push_back(maxHeap.top());
		maxHeap.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}


//ʹ�ÿ��ŵ�˼������ǰK����
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
	if (nums.size() <= 0 || k <= 0)  //ע��k>nums.size()�Ĵ���ʽ
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
