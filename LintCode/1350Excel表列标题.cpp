#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<vector>

using namespace std;


//1350. Excel表列标题
//您的提交打败了 84.67% 的提交!
string convertToTitle(int n) 
{
	// write your code here
	string res = "";
	if (n <= 0)
	{
		return res;
	}
	while (n > 0)
	{
		n--;
		char temp = (n % 26) + 'A';
		res = res + temp;
		n = n / 26;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int n = 32;
	string ans = convertToTitle(n);
	cout << ans << endl;
	system("pause");
	return 0;
}