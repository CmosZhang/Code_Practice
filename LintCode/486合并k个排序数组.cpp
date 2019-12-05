#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


void maxHeapDown(vector<int>&a, int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2 * c + 1;        // 左(left)孩子的位置
	int tmp = a[c];           // 当前(current)节点的大小
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"是左孩子，"l+1"是右孩子
		if (l < end && a[l] < a[l + 1])
			l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
		if (tmp >= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}

/*
* 堆排序(从小到大)
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void heapSortAsc(vector<int>&a, int n)
{
	int i, tmp;
	// 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, n - 1);
	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (i = n - 1; i > 0; i--)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
		// 即，保证a[i-1]是a[0...i-1]中的最大值。
		maxHeapDown(a, 0, i - 1);
	}
}
//486. 合并k个排序数组
//有时间复杂度要求。
//您的提交打败了 87.20% 的提交!
vector<int> mergekSortedArrays(vector<vector<int>> &arrays)
{
    // write your code here
	vector<int> res;
	if (arrays.empty())
	{
		return res;
	}
	int row = arrays.size();
	//int col = arrays[0].size();
	int len = 0;
	for (int i = 0; i < row; i++)
	{
		int len_temp = arrays[i].size();
		if (len_temp > 0)
		{
			len += len_temp;
		}
		for (int j = 0; j < len_temp; j++)
		{
			res.push_back(arrays[i][j]);
		}
	}
	heapSortAsc(res, len);            // 升序排列
	return res;
}

int main()
{
	vector<vector<int>> num = { {1, 3, 5, 7},{2, 4, 6},{0, 8, 9, 10, 11} };
	vector<int> ans = mergekSortedArrays(num);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}