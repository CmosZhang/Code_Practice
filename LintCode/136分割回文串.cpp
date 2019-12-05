#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;


//136. 分割回文串
//您的提交打败了 88.80% 的提交!
bool isHuiwen(string s)
{
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void dfs(string &str,vector<string> &temp, vector<vector<string>>&res, int depth)
{
	if (str.size() == depth)
	{
		res.push_back(temp);
		return;
	}
	for (int i = depth; i < str.size(); i++)
	{
		if (isHuiwen(str.substr(depth, i - depth + 1)))
		{
			temp.push_back(str.substr(depth, i - depth + 1));
			dfs(str, temp, res, i + 1);
			temp.pop_back();
		}
	}
}

vector<vector<string>> partition(string &s)
{
	// write your code here
	vector<vector<string>> res;
	if (s.empty())
	{
		return res;
	}
	vector<string> temp;
	dfs(s, temp, res, 0);
	return res;
}

int main()
{
	string s = "aab";
	vector<vector<string>> res = partition(s);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << " " << endl;
	}
	system("pause");
	return 0;
}