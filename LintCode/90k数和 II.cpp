#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


//90. k数和 II
//
//使用DFS算法来求解
void dfs(vector<vector<int>>&res, vector<int>&path, vector<int>&A, int index, int target, int k)
{
	if (k == 0 && target == 0)
	{
		res.push_back(path);
		return;
	}
	for (int i = index; i < A.size(); i++)
	{
		if (target < A[i])
		{
			break;
		}
		path.push_back(A[i]);
		dfs(res, path, A, i + 1, target - A[i], k - 1);
		path.pop_back();
	}
}

vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
	// write your code here
	vector<vector<int>> res;
	if (A.empty() || k > A.size())
	{
		return res;
	}
	vector<int> path;
	dfs(res, path, A, 0, target, k);
	return res;
}

int main()
{
	vector<int> A = { 1,2,3,4 };
	int k = 2, target = 5;
	vector<vector<int>> res = kSumII(A, k, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}