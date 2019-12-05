#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//388. ��k������
//�����ύ����� 99.80% ���ύ!

//ʹ�õݹ�ķ�ʽ������
//�ݹ�ⷨ
//���磬nums = [1, 2, 3, 4]��ȫ���У����ĸ�λ��
//����һ��Ԫ��Ϊ1ʱ���൱����2, 3, 4��ȫ���У�
//���ڴ������У���2Ϊ��һ��Ԫ��ʱ���൱����3, 4��ȫ���У�
//�ֿ��Լ������֣�3Ϊ��һ��Ԫ�أ�4����Ϊһ��ȫ����...
//����һ��Ԫ��Ϊ2ʱ���൱����1, 3, 4��ȫ���У�
//���ڴ������У���1Ϊ��һ��Ԫ��ʱ���൱����3, 4��ȫ���У�
//�ֿ��Լ������֣�3Ϊ��һ��Ԫ�أ�4����Ϊһ��ȫ����...

void per(vector<int> nums, int start, vector<vector<int> > &result)
{
	if (start == nums.size() - 1)
	{
		result.push_back(nums);
	}
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			if (i == start || nums[i] != nums[start])
			{
				swap(nums[start], nums[i]);
				per(nums, start + 1, result);
			}
		}
	}
}

vector<vector<int>> permute(vector<int> &nums)
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(), nums.end());
	per(nums, 0, res);
	return res;
}

string getPermutation(int n, int k)
{
	// write your code here
	string str;
	if (n <= 0 || k <= 0)
	{
		return str;
	}
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}
	vector<vector<int>>res = permute(nums);
	vector<int> temp = res[k - 1];
	str.resize(n);
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] = temp[i] + '0';
		str[i] = (char)temp[i];
	}
	return str;
}


int main()
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>>res;
	res = permute(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	int n = 3, k = 4;
	string str = getPermutation(3, 5);
	cout << str << endl;
	system("pause");
	return 1;
}