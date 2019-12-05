#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

bool isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i*i < num; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

//699. �ж�k������֮�� 
//�����ύ����� 83.87% ���ύ!
bool isSumOfKPrimes(int n, int k) 
{
	// write your code here
	if (n < 2 * k || k <= 0)
		return false;
	if (k == 1)
		return isPrime(n);
	//��kҲΪż����k=2q����n>=4q��n���Էֳ�q�����ڵ���4���������ݲ��룬ÿ�����ֿ��Ա�ʾΪ���������ĺͣ��ʿ��Ա�ʾΪk����2q���������ĺͣ�����true
	//��kΪ������Ϊ�˱�֤n������k�����ĺͣ��ش�������2������isSumOfKPrimes(n - 2, k - 1)
	if (n % 2 == 0)
	{
		if (k % 2 == 0)
			return true;
		else
			return isSumOfKPrimes(n - 2, k - 1);
	}
	//��kΪż����n��������ż����������ɣ��ش�������2������isSumOfKPrimes(n - 2, k - 1)
	//��kΪ��������Ȼ��������һ������������isSumOfKPrimes(n - 3, k - 1)
	else
	{
		if (k % 2 == 0)
			return isSumOfKPrimes(n - 2, k - 1);
		else
			return isSumOfKPrimes(n - 3, k - 1);
	}
}



int main()
{
	bool flag = false;
	int n = 10;
	int k = 2;
	flag = isSumOfKPrimes(n, k);
	cout << flag << endl;
	system("pause");
	return 0;
}