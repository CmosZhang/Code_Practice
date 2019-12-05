#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//4. ���� II
int nthUglyNumber(int n)
{
	// write your code here
	if (n<7)
	{
		return n;
	}
	int t1 = 0, t2 = 0, t3 = 0;
	vector<int> res;
	int t0 = 1;
	res.push_back(t0);
	int num;
	while (res.size()<n)
	{
		num = min(res[t1] * 2, min(res[t2] * 3, res[t3] * 5));
		if (num == res[t1] * 2)
			t1++;
		if (num == res[t2] * 3)
			t2++;
		if (num == res[t3] * 5)
			t3++;
		res.push_back(num);
	}
	return num;
}


//518����������
// ���100%���ύ����ʱ7ms.
int nthSuperUglyNumber(int n, vector<int> &primes)
{
	// write your code here
	if (primes.size() <= 0 || n <= 0)
	{
		return 0;
	}
	int len = primes.size();
	//ͳ�Ƴ����ǻ�����һ�����ӵõ��ġ�
	vector<int>count(len, 0);
	//�洢���
	vector<int>res;
	res.push_back(1);
	int temp, min_val;
	while (res.size() < n)
	{
		min_val = INT_MAX;
		for (int i = 0; i < len; i++)
		{
			temp = res[count[i]] * primes[i];
			min_val = min(min_val, temp);
		}
		//cout << min_val << endl;
		for (int i = 0; i < len; i++)
		{
			if (min_val == res[count[i]] * primes[i])
			{
				count[i]++;
				//break �ⲻ��break��
				//������6������2��3���Ҳ������3��2��ɡ�
				//break ��ͻ��ٿ���һ�������
			}
		}
		res.push_back(min_val);
	}
	return min_val;
}

int main()
{
	vector<int>primes = { 2, 3, 5 };
	int n = 11;
	int res;
	res = nthSuperUglyNumber(11, primes);
	cout << res << endl;
	system("pause");
	return 1;
}