#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1217. �ܺ�������
//
//Time Limit Exceeded.��һ���汾ʱ�临�Ӷȸߡ�
//�ڶ����汾���ǳ���ʱ�����ơ�
//�������汾���ǳ���ʱ�����ơ�
int totalHammingDistance(vector<int> &nums)
{
	// Write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int sum = 0;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			int temp = nums[i] ^ nums[j];
			for (int k = 0; k < 32; k++)   //��λ�𲽲���
			{
				if ((temp >> k) & 1)
				{
					sum++;
				}
			}
			//while (temp)
			//{
			//	int r = temp % 2;
			//	if (r == 1)
			//	{
			//		sum++;
			//	}
			//	temp >>= 1;
			//}
			//while (temp)
			//{
			//	sum++;
			//	// temp & (temp - 1)ÿһ�ο��Լ�һ��1
			//	temp = temp & (temp - 1);
			//}
		}
	}
	return sum;
}
/*
����Ĵ𰸡�
//������ϸ�۲��ۼƺ��������0��1�ĸ��������ǿ��Է�����ʵ����0�ĸ�������1�ĸ�����
//�����������Ҫ�Ĺ��ɣ���ô�������ӭ�ж����ˣ�ֻҪͳ�Ƴ�ÿһλ��1�ĸ������ɣ�
int totalHammingDistance(vector<int> &nums) 
{
	// Write your code here
	int res=0,n=nums.size();
	for(int i=0;i<32;++i)
	{
		int cnt=0;
		for(int num:nums)
		{
			if(num&(1<<i))
			{
				++cnt;
			}
		}
		res+=cnt*(n-cnt);
	}
	return res;
}
*/

int hammingDistance(int x, int y)
{
	// write your code here
	int sum = 0;
	int temp = x ^ y;
	for (int k = 0; k < 32; k++)   //��λ�𲽲���
	{
		//if ((((x >> k) & 1)^((y >> k) & 1)) == 1)//������Ҳ����
		//{
		//	sum++;
		//}
		if ((temp >> k) & 1)
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	vector<int> num = { 4,14,2 };
	int res = totalHammingDistance(num);
	int x = 1, y = 4;
	int sum = hammingDistance(x, y);
	cout << sum << endl;
	system("pause");
	return 1;
}