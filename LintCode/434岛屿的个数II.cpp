#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

//434.岛屿的个数II
//思路：如果每次位置发生变化，不适合用搜索的方法来做，适合用并查集的方法来做。
//您的提交打败了 43.00% 的提交!

//寻找root的最高层岛屿
int unionSearch(int root, vector<int>&nums)
{
	while (root != nums[root])
	{
		nums[root] = nums[nums[root]];
		root = nums[root];
	}
	return root;
}


vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
	vector<int> res;
	if (n <= 0 || m <= 0 || operators.empty())
	{
		return res;
	}

	vector<int> nums(n*m + 1, 0);//下标表示岛屿的位置
	vector<vector<int>> dic = { {1,0},{-1,0},{0,1},{0,-1} };//方便遍历上下左右4个位置
	int count = 0;
	for (auto c : operators)
	{
		int pos = c.x*m + c.y + 1;
		//若nums[pos]不为0，则岛屿已经出现过，直接返回现有的岛屿数目
		if (nums[pos] > 0)
		{
			res.push_back(count);
			continue;
		}
		//初始化nums[pos]为pos,表示pos最高层的岛屿是本身，此时岛屿数+1
		nums[pos] = pos;
		count++;
		for (auto t : dic)
		{
			int a = c.x + t[0];
			int b = c.y + t[1];
			int tmp = a * m + b + 1;
			if (a < 0 || a >= n || b < 0 || b >= m || nums[tmp] == 0)
			{
				continue;
			}
			//tmp表示pos的相邻位置,root为tmp的最高层岛屿
			//root!=pos表示pos与root并不属于同一个大岛屿,把pos并入root所在的大岛,
			//nums[pos]=root,并将pos置为root避免重复计算,此时岛屿数目-1
			int root = unionSearch(tmp, nums);
			if (root != pos)
			{
				nums[pos] = root;
				pos = root;
				--count;
			}
		}
		res.push_back(count);
	}
	return res;
}

int main()
{
	int n = 4, m = 5;
	vector<Point> temp = { {1,1 },{0, 1},{3, 3},{3, 4} };
	vector<int> num = numIslands2(n, m, temp);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}