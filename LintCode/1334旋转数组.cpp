#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;


//1334. ��ת����
//�����ύ����� 100.00% ���ύ!
vector<int> rotate(vector<int> &nums, int k)
{
	if (nums.empty() || k == 0)
	{
		return nums;
	}
	int len = nums.size();
	vector<int> res;
	res = nums;
	k = k % len;
	for (int i = 0; i < len; i++)
	{
		if (i < k)
		{
			res[i] = nums[len + i - k];
		}
		else
		{
			res[i] = nums[i - k];
		}
	}
	return res;
}