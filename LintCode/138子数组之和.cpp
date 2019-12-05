#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//138. ������֮��
//�����ύ����� 86.80% ���ύ!
vector<int> subarraySum(vector<int> &nums)
{
	// write your code here
	vector<int>res;
	if (nums.empty())
	{
		return res;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum = sum + nums[i];
		//����ֻ��һ��Ԫ�أ���ֵΪ0�������
		if (sum == 0)
		{
			res.push_back(i);
			return res;
		}
		for (int j = i + 1; j < nums.size(); j++)
		{
			sum = sum + nums[j];
			if (sum == 0)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
		sum = 0;
	}
}

int main()
{
	vector<int>num = { -3, 1, 2, -3, 4 };
	vector<int>res = subarraySum(num);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}