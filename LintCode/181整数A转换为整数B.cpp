#include<iostream>
#include<list> 
#include<bitset>

using namespace std;

void BinaryRecursion(int n)
{
	int a;
	a = n % 2;
	n = n>>1;
	if (n == 0)
		;
	else
		BinaryRecursion(n);
	cout<<a;
}

int bitSwapRequired(int a, int b) 
{
	int change = 0;
	int flag = 1;
	int i = 0;
	int j = 0;
	while (flag) 
	{
		i = a & flag;
		j = b & flag;
		/*cout<<"BinaryRecursion(i):";
		BinaryRecursion(i);
		cout << "\n";*/
		if (i ^ j)
			change++;
		flag = flag << 1;
	}
	return change;
}

int main()
{
	int i, n, m;
	cout << "please input i:\n";
	cin >> i;
	cout << "please input n:\n";
	cin >> n;
	m = bitSwapRequired(i, n);
	cout << "change bits:\n";
	cout << m << endl;
	system("pause");
}