#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//15ȫ���С�
//�����ύ����� 88.40% ���ύ!

//ʹ�õݹ�ķ�ʽ������
//�ݹ�ⷨ
//���磬nums = [1, 2, 3, 4]��ȫ���У����ĸ�λ��
//����һ��Ԫ��Ϊ1ʱ���൱����2, 3, 4��ȫ���У�
//���ڴ������У���2Ϊ��һ��Ԫ��ʱ���൱����3, 4��ȫ���У�
//�ֿ��Լ������֣�3Ϊ��һ��Ԫ�أ�4����Ϊһ��ȫ����...
//����һ��Ԫ��Ϊ2ʱ���൱����1, 3, 4��ȫ���У�
//���ڴ������У���1Ϊ��һ��Ԫ��ʱ���൱����3, 4��ȫ���У�
//�ֿ��Լ������֣�3Ϊ��һ��Ԫ�أ�4����Ϊһ��ȫ����...

//��ȫ����
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
			if (nums[i] != nums[start] || i == start)
			{
				swap(nums[start], nums[i]);
				per(nums, start + 1, result);
				//swap(nums[start], nums[i]);
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

//16. ���ظ�Ԫ�ص�����
//�����ύ����� 76.00% ���ύ!
void per2(vector<int> nums, int start, vector<vector<int> > &result)
{
	if (start == nums.size() - 1)
	{
		result.push_back(nums);
	}
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			if (nums[i] != nums[start] || i == start)
			{
				swap(nums[start], nums[i]);
				per(nums, start + 1, result);
				//swap(nums[start], nums[i]);
			}
		}
	}
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(), nums.end());
	per2(nums, 0, res);
	return res;
}



int main()
{
	vector<int> nums = {1,2,3};
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
	system("pause");
	return 1;
}