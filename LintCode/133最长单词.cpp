#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//133. 最长单词
//您的提交打败了 85.00% 的提交!
vector<string> longestWords(vector<string> &dictionary) 
{
	// write your code here
	vector<string> result;
	int size = dictionary.size(), maxLen = 0;
	if (size <= 0)
	{
		return result;
	}
	maxLen = dictionary[0].size();
	result.push_back(dictionary[0]);
	for (int i = 1; i<size; i++)
	{
		if (maxLen < dictionary[i].size())
		{
			maxLen = dictionary[i].size();
			result.clear();
			result.push_back(dictionary[i]);
		}
		else if (maxLen == dictionary[i].size())
		{
			result.push_back(dictionary[i]);
		}
	}
	return result;
}

int main()
{
	vector<string >str = { "dog","google","facebook","internationalization","blabla" };
	vector<string> res = longestWords(str);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}