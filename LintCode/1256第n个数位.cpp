#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//1256. ��n����λ
//�����ύ����� 89.22% ���ύ!
//���ַ����ڴ泬�����ơ��ռ临�Ӷ�̫�ߡ�
/*
* �������ȷ���һ��λ���͹���
* ��λ����1-9��һ��9��,����9������
* 2λ����10-99,һ��90��������180������
* 3λ����100-999��һ��900��������2700������
* 4λ����1000-9999��һ��9000��������36000������
* �Դ����ƣ�
* �������ǾͿ������ȶ�λ�����ĸ��������ҵ����Ӧ������
*/
int findNthDigit(int n) 
{
	// write your code here
	/*if (n <= 0)
	{
		return 0;
	}
	vector<int> temp;
	for (int i = 1; i < 10; i++)
	{
		temp.push_back(i);
	}
	int num = 10;
	while (temp.size() <= n)
	{
		int a = num % 10;
		while (num / 10)
		{
			num = num / 10;//num �Ѿ��ı䡣�߼���������
			temp.push_back(num);
		}
		temp.push_back(a);
		num++;
	}
	return temp[n - 1];*/
	int len = 1, base = 1;
	while (n > 9L * base * len) //Ϊʲô����Ҫһ��L.��ֹ���
	{
		n -= 9 * base * len;
		len++;
		base *= 10;
	}
	int curNum = (n - 1) / len + base, digit = 0;
	cout << curNum << endl;
	for (int i = (n - 1) % len; i<len; ++i) 
	{
		digit = curNum % 10;
		curNum /= 10;
	}
	return digit;
}

int main()
{
	int m = 1297;
	int res = findNthDigit(m);
	cout << res << endl;
	system("pause");
	return 1;
}