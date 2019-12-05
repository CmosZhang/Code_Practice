#include<iostream>
#include<list> 
#include<bitset>

using namespace std;

int countPrimeSetBits(int L, int R) 
{
	bool flag[33];
	for (int i = 0; i <= 32; i++) 
	{
		flag[i] = true;
	}
	for (int i = 2; i <= 32; i++) 
	{
		if (flag[i]) 
		{
			for (int j = i + i; j <= 32; j += i) 
			{ //筛选法找出[2,32]内所有的质数
				flag[j] = false;
			}
		}
	}
	int ans = 0;
	for (; L <= R; L++) 
	{
		int cnt = 0;
		for (int i = 0; i<32; i++) 
		{
			if (L >> i & 1) 
			{ //如果该位上的二进制数字是1，那么就将cnt++；
				cnt++;
			}
		}
		if (flag[cnt] && cnt != 1) 
		{ //如果cnt是质数并且不等于1，那么ans++
			ans++;
		}
	}
	return ans;
}

int main()
{
	int L, R, result;
	cout << "please input L:\n";
	cin >> L;
	cout << "please input R:\n";
	cin >> R;
	result = countPrimeSetBits(L, R);
	cout << "prime set bits:\n";
	cout << result << endl;
	system("pause");
}