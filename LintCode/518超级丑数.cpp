#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//4. 丑数 II
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


//518超级丑数。
// 打败100%的提交，耗时7ms.
int nthSuperUglyNumber(int n, vector<int> &primes)
{
	// write your code here
	if (primes.size() <= 0 || n <= 0)
	{
		return 0;
	}
	int len = primes.size();
	//统计丑数是基于那一个因子得到的。
	vector<int>count(len, 0);
	//存储结果
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
				//break 这不能break，
				//举例，6可以由2个3组成也可以由3个2组成。
				//break 后就会少考虑一种情况。
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