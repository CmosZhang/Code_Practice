#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//394. Ӳ���ų���
//�����ύ����� 89.20% ���ύ!
//ֻҪn��3�ı����������ֱ��䣬����3�ı��������ֱ�ʤ
bool firstWillWin(int n)
{
	// write your code here
	if (n <= 0)
	{
		return false;
	}
	if (n % 3 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}