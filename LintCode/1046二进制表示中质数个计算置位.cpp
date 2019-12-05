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
			{ //ɸѡ���ҳ�[2,32]�����е�����
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
			{ //�����λ�ϵĶ�����������1����ô�ͽ�cnt++��
				cnt++;
			}
		}
		if (flag[cnt] && cnt != 1) 
		{ //���cnt���������Ҳ�����1����ôans++
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