#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//152. ×éºÏ
//
vector<vector<int>> combine(int n, int k)
{
	// write your code here
	vector<vector<int>> res;
	vector<int> temp;
	if (n <= 0 || k <= 0 || k > n)
	{
		res.push_back(temp);
		return res;
	}
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp.push_back(i + 1);
			temp.push_back(j + 1);
			res.push_back(temp);
			temp.clear();
		}
	}
	return res;
}


int main()
{
	int n = 4, k = 2;
	vector<vector<int>> res;
	res = combine(n, k);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}