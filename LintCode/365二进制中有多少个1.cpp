#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//365. ���������ж��ٸ�1 
//�����ύ����� 70.80% ���ύ!
//��һ���ύû�п��ǵ�������
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