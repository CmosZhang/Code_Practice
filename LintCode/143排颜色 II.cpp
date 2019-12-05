#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//143. 排颜色 II
//使用快排，无视k的存在
//您的提交打败了 25.40% 的提交!
//时间复杂度为O(nlogn)
//void sortColors2(vector<int> &colors, int k)
//{
//	// write your code here
//	sort(colors.begin(), colors.end());
//}

//使用计数排序
//时间复杂度O(n),空间复杂度O(k)
//您的提交打败了 100.00% 的提交!
void sortColors2(vector<int> &colors, int k)
{
	// write your code here
	vector<int> count(k + 1, 0);
	for (int i = 0; i < colors.size(); i++)
	{
		count[colors[i]]++;
	}

	int index = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			colors[index] = i;
			index++;
		}
	}
}