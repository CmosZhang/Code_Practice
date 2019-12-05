#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//135. 数字组合
//您的提交打败了 81.00% 的提交!
void dfs(vector<vector<int>>&result, vector<int>&candidates, vector<int>&temp, int target, int index,int sum)
{
	if (sum == target)
	{
		result.push_back(temp);
		return;
	}
	else if(sum > target)
	{
		return;
	}

	for (int i = index; i < candidates.size(); i++)
	{
		if (i != index && candidates[i] == candidates[i - 1])
			continue;
		temp.push_back(candidates[i]);
		sum += candidates[i];
		//dfs(result, candidates, temp, target, i, sum); //135题
		dfs(result, candidates, temp, target, i + 1, sum);//153题
		sum -= temp[temp.size() - 1];
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	// write your code here
	vector<vector<int>> result;
	if (candidates.empty())
	{
		result.push_back(candidates);
		return result;
	}
	vector<int> temp;
	sort(candidates.begin(), candidates.end());//这一步必不可少，输出的结果要求有序
	dfs(result, candidates, temp, target, 0, 0);
	return result;
}



//153. 数字组合 II
//您的提交打败了 76.40% 的提交!
vector<vector<int>> combinationSum2(vector<int> &num, int target)
{
	// write your code here
	vector<vector<int>> result;
	if (num.empty())
	{
		result.push_back(num);
		return result;
	}
	vector<int> temp;
	sort(num.begin(), num.end());//这一步必不可少，输出的结果要求有序
	dfs(result, num, temp, target, 0, 0);
	return result;
}

int main()
{
	int target = 8;
	vector<int> nums = { 10,1,6,7,2,1,5 };
	vector<vector<int>> res = combinationSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;

}
