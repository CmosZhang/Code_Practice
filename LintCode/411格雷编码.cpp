#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//411. ���ױ���
//�����ύ����� 57.20% ���ύ!
vector<int> grayCode(int n) 
{
	// write your code here
	vector<int> res;
	if (n < 0)
	{
		return res;
	}
	for (int i = 0; i < pow(2, n); i++)
	{
		int temp = (i >> 1) ^ i;
		res.push_back(temp);
	}
	return res;
}
int main()
{
	int n = 2;
	vector<int> res;
	res = grayCode(n);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}