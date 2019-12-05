#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//182. 删除数字
//
//string DeleteDigits(string &A, int k)
//{
//	// write your code here
//	string res;
//	if (A.size() <= 0 || k > A.size())
//	{
//		return res;
//	}
//	int len = A.size();
//	vector<int> temp(len, 0);
//	//vector<int> temp1(len, 0);
//	for (int i = 0; i < len; i++)
//	{
//		temp[i] = A[i] - '0'; //将字符类型转换为数字。
//		//temp1[i] = A[i] - '0';
//	}
//	//找到最大的前K位数，将他们设置为-1;
//	while (k--)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			if (temp[j] <= temp[j + 1])
//			{
//				j++;
//				temp[j] = -1;
//				break;
//			}
//		}
//	}
//	int count = len - k;
//	res.resize(count);//计算字符串最后的有效长度。
//	int j = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (temp[i] == -1)
//		{
//			continue;
//		}
//		temp[i] = temp[i] + '0';//将数字转换成了对应的字符数字相对应的ASCII
//		res[j] = (char)temp[i];//转换成字符数字。
//		j++;
//	}
//	int m;
//	for (m = 0; res[m] == '0'; ++m);//找到第一个不为0的位置。
//    return  res.substr(m);
//}

//您的提交打败了 96.80% 的提交!
string DeleteDigits(string &A, int k)
{
	// write your code here
	string ret;
	if(A.empty())
	   return ret;
	ret = A;
	while(k--)
	{
		int i = 0;
		while (i < ret.length() - 1 && ret[i] <= ret[i + 1])
			++i;
		ret = ret.substr(0, i) + ret.substr(i + 1);
	}
	int i;
	for (i = 0; ret[i] == '0'; ++i);//找到第一个不为0的位置。
	ret = ret.substr(i);
	return ret;
}



int main()
{
	string str = "178542";
	int k = 4;
	string res = DeleteDigits(str, 4);
	cout << res << endl;
	system("pause");
	return 1;
}