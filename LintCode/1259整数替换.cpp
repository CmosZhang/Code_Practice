#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//1259. �����滻
//�����ύ����� 75.00% ���ύ!
int integerReplacement(int n) 
{
	// Write your code here
	if (n == 1)
	{
		return 0;
	}
	if (n % 2 == 0)
	{
		return integerReplacement(n / 2) + 1;
	}
	else 
	{
		if (n == INT_MAX)
		{
			return integerReplacement(n - 1) + 1;
		}
		return min(integerReplacement(n - 1) + 1, integerReplacement(n + 1) + 1);
	}
}

int main()
{
	int m = 10;
	int count=integerReplacement(m);
	cout << count << endl;
	system("pause");
	return 0;
}