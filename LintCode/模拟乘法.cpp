#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ģ��˷�������a*b��ֵ
//ʱ�临�Ӷ���Ҫ��
//��������ʱ�临�Ӷ�ΪO(min(a,b));
//�϶��������Ž�
//int multi(int a, int b)
//{
//	int ans = 0;
//	if (b == 0 || a == 0)
//	{
//		return ans;
//	}
//	else if (b > 0)
//	{
//		for (int i = 1; i <= b; i++)
//		{
//			ans += a;
//		}
//		return ans;
//	}
//	else
//	{
//		for (int i = 1; i <= abs(b); i++)
//		{
//			ans += a;
//		}
//		return -ans;
//	}
//	return ans;
//}

//�ڶ��ַ�����
int multi(int a, int b)
{
	int sign = 1;
	if (b < 0)
	{
		sign = -sign;
		b = -b;
	}
	if (a < 0)
	{
		sign = -sign;
		a = -a;
	}
	int ret = 0;
	//�����㷨��ʹ�õ�λ����
	while (b)
	{
		if (b & 1)
		{
			ret += a;
		}
		a <<= 1;
		b >>= 1;
	}
	if (sign < 0)
	{
		return -ret;
	}
	return ret;
}

int main()
{
	int a = 4, b = -4;
	cout << multi(a, b) << endl;
	system("pause");
	return 0;
}