#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//135. �������
//�����ύ����� 81.00% ���ύ!
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
		//dfs(result, candidates, temp, target, i, sum); //135��
		dfs(result, candidates, temp, target, i + 1, sum);//153��
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
	sort(candidates.begin(), candidates.end());//��һ���ز����٣�����Ľ��Ҫ������
	dfs(result, candidates, temp, target, 0, 0);
	return result;
}



//153. ������� II
//�����ύ����� 76.40% ���ύ!
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
	sort(num.begin(), num.end());//��һ���ز����٣�����Ľ��Ҫ������
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
