#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//119. 编辑距离
//您的提交打败了 95.40% 的提交!
int minDistance(string &word1, string &word2) 
{
	// write your code here
	int len1 = word1.size();
	int len2 = word2.size();
	if (len1 == 0)
	{
		return len2;
	}
	if (len2 == 0)
	{
		return len1;
	}
	vector<vector<int>> dis_matrix(len1 + 1, vector<int>(len2 + 1, 0));
	for (int j = 0; j <= len2; j++)
		dis_matrix[0][j] = j;
	for (int i = 0; i <= len1; i++)
		dis_matrix[i][0] = i;

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++) 
		{
			int tmp_step;
			if (word1[i - 1] == word2[j - 1])//注意这里下标容易写错。一开始写成了if(word[i]==word2[j])
				tmp_step = 0 + dis_matrix[i - 1][j - 1];
			else
				tmp_step = 1 + dis_matrix[i - 1][j - 1];
			int tmp_step2 = min((dis_matrix[i - 1][j] + 1), (dis_matrix[i][j - 1] + 1));
			dis_matrix[i][j] = min(tmp_step2, tmp_step);
		}
	}
	return dis_matrix[len1][len2];
}