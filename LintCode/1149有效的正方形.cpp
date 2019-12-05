#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


//1149. 有效的正方形
//您的提交打败了 89.66% 的提交!
//纯数学问题
bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
	// Write your code here
	if (p1.empty() || p2.empty() || p3.empty() || p4.empty())
	{
		return false;
	}
	vector<int> temp;
	int p12 = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
	temp.push_back(p12);
	int p13 = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
	temp.push_back(p13);
	int p14 = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
	temp.push_back(p14);
	int p23 = pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2);
	temp.push_back(p23);
	int p24 = pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2);
	temp.push_back(p24);
	int p34 = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
	temp.push_back(p34);
	sort(temp.begin(), temp.end());
	for (int i = 1; i < 4; i++)
	{
		if (temp[i] != temp[i - 1])
		{
			return false;
		}
	}
	if (temp[temp.size() - 1] != temp[temp.size() - 2])
	{
		return false;
	}
	return true;
}
