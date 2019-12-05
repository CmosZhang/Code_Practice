#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>

using namespace std;

//911. ���������֮��Ϊk
//�������
//�����ύ����� 9.20% ���ύ!
//ʱ�临�Ӷ�ΪO(n^2)
int maxSubArrayLen(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty())
	{
		return 0;
	}
	int res = INT_MIN;
	int sum = 0;
	int len = nums.size();
	if (len == 1 && nums[0] == k)
	{
		res = 1;
	}
	for (int i = 0; i < len - 1; i++)
	{
		sum += nums[i];
		for (int j = i + 1; j < len; j++)
		{
			sum += nums[j];
			if (sum == k)
			{
				res = max(res, j - i + 1);
			}
		}
		sum = 0;
	}
	return res;
}

//��ĿҪ��
//ʱ�临�Ӷ�ΪO(n)
//��mapά��ǰ׺�Ͷ�Ӧ������յ�λ�ã�Ȼ��ö�������鿪ʼλ�ã���map�н��в���
//���±�Ϊ 0 ���±�Ϊ 100���� sum = 2000��
//��������Ҫ���Ŀ�� k=800����ô����ֻҪ֪���� 0 ��ʼ��
//������ֵ��±� i��ʹ�� 0 �� i ֮��ĺ�Ϊ 1200��
//�������ܱ�֤ i+1 �� 1000 �ĺ�Ϊ 800��
//ͬʱ���ܱ�֤����������� 1000 ��β�����ĳ���
int maxSubArrayLen(vector<int> &nums, int k) {
	if (nums.empty())
	{
		return 0;
	}
	unordered_map<int, int>m;
	int n = nums.size();
	vector<int> sum(n + 1, 0);
	m[k] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + nums[i - 1];
		if (m.find(sum[i]) != m.end())
		{
			ans = max(ans, i - m[sum[i]]);
		}
		if (m.find(sum[i] + k) == m.end())
		{
			m[sum[i] + k] = i;
		}
	}
	return ans;
}