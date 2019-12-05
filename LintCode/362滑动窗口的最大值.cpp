#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;


//362. 滑动窗口的最大值
//90% 数据通过测试
//时间复杂度太高。
//在牛客网上数据全都通过。
//vector<int> maxSlidingWindow(vector<int> &nums, int k)
//{
//	// write your code here
    //vector<int> res;
	//if (nums.empty() || nums.size() < k|| k <= 0 )
	//{
	//	return res;
	//}
	//int len = nums.size();
	//for (int i = 0; i <= len - k; i++)
	//{
	//	int max = INT_MIN;
	//	for (int j = 0; j < k; j++)
	//	{
	//		if (nums[i + j] > max)
	//		{
	//			max = nums[i + j];
	//		}
	//	}
	//	res.push_back(max);
	//}
	//return res;
//}

//您的提交打败了 65.20% 的提交!
//利用双向队列来做
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
	vector<int> res;
	if (nums.empty() || nums.size() < k || k <= 0)
	{
		return res;
	}
	int len = nums.size();
	deque<int> index;
	for (int i = 0; i < len; i++)
	{
		//从队列后面弹出比当前元素小的的值
		while (index.empty() != true && nums[i] >= nums[index.back()])
		{
			index.pop_back();
		}
		if(index.empty() != true && index.front() <= i - k)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
		{
			index.pop_front();
		}
		index.push_back(i);//把每次滑动的nums下标加入队列
		if (i + 1 >= k)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
		{
			res.push_back(nums[index.front()]);
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,2,7 ,7,8};
	int k = 3;
	vector<int> res = maxSlidingWindow(nums, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}