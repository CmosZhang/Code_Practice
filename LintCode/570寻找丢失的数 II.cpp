#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//570. 寻找丢失的数 II
//使用回溯的方法来做
//您的提交打败了 74.60% 的提交!
int findTheNum(vector<int>&d, int index, string &str)
{
	int res = -1;
	if (index == str.size() && d[0] == d.size() - 2)
	{//迭代需要的出口，当index到达str最后的下一个位置并且数字总数达到n-1个时返回剩余的数
		for (int i = 1; i < d.size(); i++)
		{
			if (d[i] == 0)
			{
				res = i;
			}
		}
	}
	if (str[index] == '0')//指向的下一个数以0开始直接返回
	{
		return res;
	}
	else
	{
		int temp1 = str[index] - '0';//第一个数字
		if (d[temp1] == 0)
		{
			d[temp1] = 1;//深度优先搜索找到合适的结果
			d[0]++;//计数+1
			int ret = findTheNum(d, index + 1, str);
			if (ret != -1)
				res = ret;//如果能找到更改res值
			d[temp1] = 0;//回溯的套路，恢复原状
			d[0]--;
		}
		if (index + 1 < str.size())
		{
			int temp2 = str[index + 1] - '0';
			temp2 = temp2 + temp1 * 10;//如果两个数组成
			if (temp2 < d.size() && d[temp2] == 0)
			{
				d[temp2] = 1;
				d[0]++;
				int ret = findTheNum(d, index + 2, str);
				if (ret != -1)
					res = ret;
				d[temp2] = 0;
				d[0]--;
			}
		}
	}
	return res;//返回最后的结果
}

int findMissing2(int n, string &str) {
	// write your code here
	if (str.empty() || n < 1)
	{
		return 0;
	}
	vector<int> dict(n + 1, 0);//数组用于标记数字是否出现过，dict[0]用来记录已经出现了多少个数字
	return findTheNum(dict, 0, str);
}


//第二种方法
//您的提交打败了 75.60% 的提交!
void search(int n, string &str, int index[], vector<bool>&exist, int len)
{
	if(index[0]>=len)
	{
		return;
	}
	if (str[index[0]] == '0')
	{
		return;
	}
	if (!exist[str[index[0]] - '0'])
	{
		exist[str[index[0]] - '0'] = true;
		index[0]++;
		search(n, str, index, exist, len);
		if (index[0] >= len)
			return;
		index[0]--;
		exist[str[index[0]] - '0'] = false;
	}
	if (index[0] < len - 1)
	{
		int a = str[index[0]] - '0';
		int b = str[index[0] + 1] - '0';
		int value = 10 * a + b;
		if (value <= n && !exist[value])
		{
			exist[value] = true;
			index[0] += 2;
			search(n, str, index, exist, len);
			if (index[0] >= len)
				return;
			index[0] -= 2;
			exist[value] = false;
		}
	}
}

int findMissing2(int n, string &str)
{
	if (n < 1 || str.empty())
	{
		return 0;
	}
	int len = str.size();
	vector<bool> exist(n + 1, false);
	int index[] = { 0 };
	search(n, str, index, exist, len);
	for (int i = 1; i <= len; i++)
	{
		if (!exist[i])
		{
			return i;
		}
	}
	return 0;
}


int main()
{
	string str = "19201234567891011121314151618";
	int n = 20;
	cout << findMissing2(n, str) << endl;
	system("pause");
	return 0;
}