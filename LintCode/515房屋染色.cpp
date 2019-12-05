#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//515����Ⱦɫ
int minCost(vector<vector<int>> &costs) 
{
	// write your code here
	if (costs.size() <= 0)
	{
		return 0;
	}
	int row = costs.size();
	int col = costs[0].size();
	vector<vector<int>>dp(row, vector<int>(col, 0));
	//��һ��Ⱦ��ɫ��
	dp[0][0] = costs[0][0];
	//��һ��Ⱦ��ɫ��
	dp[0][1] = costs[0][1];
	//��һ��Ⱦ��ɫ��
	dp[0][2] = costs[0][2];
	for (int i = 1; i < row; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	}
	int res;
	res = min(dp[row - 1][0], min(dp[row - 1][1], dp[row - 1][2]));
	return res;
}

int min_k(vector<int> &arr, int k)
{
	
	int l = arr.size();
	int min = INT_MAX;
	for (int i = 0; i < l; i++)
	{
		if (i == k)
		{
			continue;
		}
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}


//516. ����Ⱦɫ II 
//����㷨̫��ʱ�䡣���28.6%���ύ���������ԣ�Ӧ��Ҫ���ַ�ʽ��
int minCostII(vector<vector<int>> &costs) 
{
	// write your code here
	if (costs.size() <= 0)
	{
		return 0;
	}
	int row = costs.size(); //���ݵĸ���
	int col = costs[0].size();//��ɫ�ĸ���
	vector<vector<int>>dp(row, vector<int>(col, 0));
	dp[0] = costs[0];

	for (int i = 1; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			dp[i][k] = min_k(dp[i-1], k) + costs[i][k];
		}
	}
	int res=dp[row-1][0];
	for (int j = 0; j < col; j++)
	{
		if (res > dp[row - 1][j])
		{
			res = dp[row - 1][j];
		}
	}
	return res;
}



int main()
{
	int res;
	vector<vector<int>>cost = { {1,2,3},{1,4,6} };
	res = minCostII(cost);
	cout << res << endl;
	system("pause");
	return 0;
}