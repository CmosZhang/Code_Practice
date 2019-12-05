#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>

using namespace std;


//406. �ʹ���S����С������
//���ص���������ĳ���
//�����ύ����� 84.00% ���ύ!
int minimumSize(vector<int> &nums, int s) {
	// write your code here
	if (nums.empty())
	{
		return -1;
	}
	int sum = 0;
	int res = INT_MAX;
	bool flag = false;
	for (int i = 0, j = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		while(sum >= s)
		{
			flag = true;
			res = min(res, i - j + 1);
			sum -= nums[j];
			j++;
		}
	}
	if (flag)
		return res;
	else
		return -1;
}