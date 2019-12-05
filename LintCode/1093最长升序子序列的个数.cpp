#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//1093. ����������еĸ���
//���ǵ�ʹ�ö�̬�滮�ķ���
//dp[i] �����Ե� i ������β������������еĳ��ȡ�
//ans[i] �����Ե� i ������β������������еĸ�����
//dp[i] = max(dp[j] + 1), nums[j] < nums[i]��
//ans[i] = sum(ans[j]), nums[j] < nums[i] and dp[j] == dp[i] - 1��
//�����ύ����� 49.41% ���ύ!
int findNumberOfLIS(vector<int> &nums) {
	// Write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	vector<int> dp(len, 0);
	dp[0] = 1;
	vector<int> ans(len, 0);
	ans[0] = 1;
	int max_len = 1;
	for (int i = 1; i < len; i++)
	{
		dp[i] = 1;
		ans[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[j]<nums[i] && dp[j] + 1>dp[i])
			{
				dp[i] = dp[j] + 1;
				ans[i] = ans[j];
			}
			else if (nums[j] < nums[i] && dp[j] + 1 == dp[i])
			{
				ans[i] += ans[j];
			}
		}
		if (dp[i] > max_len)
		{
			max_len = dp[i];
		}
	}
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		if (dp[i] == max_len)
		{
			res += ans[i];
		}
	}
	return res;
}
