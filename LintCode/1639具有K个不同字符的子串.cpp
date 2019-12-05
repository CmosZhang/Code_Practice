#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//1639. 具有K个不同字符的子串
//
int KSubstring(string &stringIn, int K)
{
	// Write your code here
	int len = stringIn.size();
	if (len <= 0 || K < 0 || len < K)
	{
		return 0;
	}

	int res = 0;
	int count = 1;

	for (int i = 0; i < len; i++)
	{

	}


	for (int i = 1; i < len - 1; i++)
	{
		if (stringIn[i] != stringIn[i - 1])
		{
			count++;
			if (stringIn[i] != stringIn[i + 1] && stringIn[i - 1] != stringIn[i + 1])
			{
				count++;
			}
			if (count == K)
			{
				res++;
				count = 1;
			}
		}
		count = 1;
	}
	return res;
}

int main()
{
	string str = "abcabc";
	int k = 3;
	int res = KSubstring(str, k);
	cout << res << endl;
	system("pause");
	return 1;
}