#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//664. �� 1
//�����ύ����� 45.02% ���ύ!
int countOnes(int num)
{
	// write your code here
	int count = 0;
	for (int i = 0; i<32; i++)   //��λ�𲽲���
	{
		if ((num >> i) & 1)
		{
			count++;
		}
	}
	return count;
}

vector<int> countBits(int num) 
{
	// write your code here
	vector<int> res;
	if (num < 0)
	{
		return res;
	}
	for (int i = 0; i <= num; i++)
	{
		int count = countOnes(i);
		res.push_back(count);
	}
	return res;
}