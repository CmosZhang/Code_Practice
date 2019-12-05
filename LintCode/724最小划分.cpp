#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//724. ��С����
//
int findMin(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	int sumt = sum;
	sum = sum / 2;
	vector<int> dp(sumt + 1, 0);
	dp[0] = 1;
	// ��������˼·������ܺ�Ϊj�ķ����Ƿ����
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = sum; j >= nums[i]; j--)
		{
			dp[j] += dp[j - nums[i]];
		}
	}
	//�Ӻ���ǰ�����������ܺ�����jʱ��������С�Ļ���
	for (int i = sum; i >= 0; i--)
	{
		if (dp[i] != 0)
			return abs(i * 2 - sumt);
	}
}