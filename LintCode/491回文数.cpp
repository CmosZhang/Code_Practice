#include<iostream>
#include<string>

using namespace std;


//判断一个正整数是不是回文数
bool isPalindrome(int num) 
{
	// write your code here
	if (num < 10)
	{
		return true;
	}
	long int a = num;
	long int sum = 0;
	while (a)
	{
		sum = sum * 10 + a % 10;
		a = a / 10;
	}
	if (num == sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a;
	cout << "input a number" << endl;
	cin >> a;
	bool flag;
	flag = isPalindrome(a);
	printf("%d", flag);
	system("pause");
	return 1;
}