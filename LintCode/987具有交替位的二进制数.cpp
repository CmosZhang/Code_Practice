#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//987. ���н���λ�Ķ�������
//�����ύ����� 100.00% ���ύ!
bool hasAlternatingBits(int n)
{
	// Write your code here
	if (n <= 0)
	{
		return false;
	}
	int r = n % 2;
	n >>= 1;
	while (n)
	{
		int count = n % 2;
		if (count^r == 0)
		{
			return false;
		}
		r = count;
		n >>= 1;
	}
	return true;
}