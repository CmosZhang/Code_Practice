#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1218. ����
//�����ύ����� 100.00% ���ύ!
//����һ���������Ĳ���
int findComplement(int num) 
{
	// Write your code here
	vector<int> temp;
	while (num)
	{
		int r = num % 2;
		temp.push_back(r);
		num >>= 1;
	}
	//temp����洢����x�Ķ����Ʊ�ʾ���ӵ�λ����λ��
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 1)
		{
			temp[i] = 0;
		}
		else
		{
			temp[i] = 1;
		}
	}
	//������ת��Ϊ10����
	int sum = 0;
	for (int i = 0; i <temp.size(); i++)
	{
		sum = sum + temp[i] * (1 << i);
	}
	return sum;
}