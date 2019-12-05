#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>


using namespace std;

//lintcode 加一 
//直接的做法是将数组转化为整数，注意该整数的类型应定义成 long long 
//防止数据过大造成运算错误。然后该整数 + 1，再将其转化为数组，
//从低位开始依次push到结果数组中，最后将结果数组翻转return出去。
vector<int> plusOne(vector<int> &digits)
{
	// write your code 
	vector<int> res;
	int l = digits.size();
	if (l <= 0)
	{
		return res;
	}
	long long num;
    long long sum = 0;
	for (int i = 0; i <l; i++)
	{
		num = digits[i]*pow(10.0, l-i-1);
		sum = sum + num;
	}
	sum = sum + 1;
	int temp;
	while (sum)
	{
		temp = sum % 10;
		res.push_back(temp);
		sum = sum / 10;
	}
	reverse(res.begin(),res.end());
	return res;
}
//vector<int> plusOne(vector<int> &digits)
//{
//	// write your code
//	int l = digits.size();
//	for (int i = l - 1; i >= 0; i--)
//	{
//		if (digits[i] != 9)
//		{
//			digits[i] += 1;
//			return digits;
//		}
//		else
//			digits[i] = 0;
//	}
//	vector <int> res;
//	res = digits;
//	res[0] = 1;
//	res.push_back(0);
//	return res;
//}
int main()
{
	int i;
	//生成一个3行3列的矩阵
	vector<int> array;
	for (int i = 0; i < 10; i++)
	{
		array.push_back(9-i);
	}
	vector<int> res;
	res = plusOne(array);
	for (int k = 0; k < res.size(); k++)
	{
		cout << res[k] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}