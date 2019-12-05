#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//727. 中国剩余定理
int remainderTheorem(vector<int> &num, vector<int> &rem)
{
	// write your code here
	if (num.size() <= 0 || rem.size() <= 0)
	{
		return -1;
	}
	//int len = num.size();
	////sort(num.begin(), num.end());
	////sort(rem.begin(), rem.end());
	//int count = 0;
	//int temp1 = 1;
	//int temp2 = 1;
	//int flag = 1;
	//while (count < 1)
	//{
	//	temp2 = temp1 * num[0] + rem[0];
	//	for (int j = 1; j < len; j++)
	//	{
	//		if (temp2%num[j] != rem[j])
	//		{
	//			flag = 0;
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		count++;
	//	}
	//	temp1++; //倍数增加.
	//	flag = 1;
	//}
	//return temp2;
	int len = num.size();
	int n = num[0];
	int r = rem[0];
	for (int i = 1; i < len; ++i)
	{
		int a = (rem[i] - r % num[i] + num[i]) % num[i];
		if (a != 0)
		{
			for (int j = 1; j <= num[i]; ++j)
			{
				if (n*j%num[i] == a)
				{
					r = n * j + r;
					break;
				}
			}
		}
		n = num[i] * n;
	}
	return r;
}

int main()
{
	vector<int>num = { 11,3,2,41,7,19,17,29,5 };
	vector<int>rem= { 7,1,1,6,4,5,11,19,4 };
	int res = remainderTheorem(num, rem);
	cout << res << endl;
	system("pause");
	return 0;
}