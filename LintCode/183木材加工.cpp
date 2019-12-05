#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//183. 木材加工
//您的提交打败了100.00% 的提交!
//木材的最大长度肯定<=数组中每一个数除k的商之和(sum)
//从数组的最大值开始遍历。
int woodCut(vector<int> &L, int k)
{
	// write your code here
	if (L.size() <= 0)
	{
		return 0;
	}
	int max = 0;//寻找最大值
	for (int i = 0; i < L.size(); i++)
	{
		if (max < L[i])
		{
			max = L[i];
		}
	}
	//使用二分查找来做。
	int low = 1;
	int high = max - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;//这样写防止堆栈溢出。
		int count = 0;
		for (int i = 0; i < L.size(); i++)
		{
			count += L[i] / mid;
		}
		if (count >= k)
		{
			low = mid + 1;
		}
		if (count < k)
		{
			high = mid - 1;
		}
	}
	return high;
}

int main()
{
	vector<int> wood = { 232, 124, 456 };
	int k = 7;
	int res = woodCut(wood, k);
	cout << res << endl;
	system("pause");
	return 1;
}