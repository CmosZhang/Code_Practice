#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//721. ��һ��ϡ����
//�����ύ����� 97.77% ���ύ!
//ϡ������������󣬲����໥�������0��1.
//���Ϊ110�������ϡ����Ϊ1000.
int nextSparseNum(int x) 
{
	// write your code here
	vector<int> temp;
	int n = x;
	while (n)
	{
		int r = n % 2;
		temp.push_back(r);
		n >>= 1;
	}
	//temp����洢����x�Ķ����Ʊ�ʾ���ӵ�λ����λ��
	temp.push_back(0); //������ܻ��һλ
	int len = temp.size();
	int pos = 0;
	for (int i = 1; i < len - 1; i++)
	{
		if (temp[i] == 1 && temp[i - 1] == 1 && temp[i + 1] == 0)
		{
			temp[i + 1] = 1;
			for (int j = i; j >= pos; j--)
			{
				temp[j] = 0;
			}	
		    pos = i + 1;
		}
	}
	//n��32λ�����ƴ洢���Ӹ�λ����λ
	//������ת��Ϊ10����
	int sum = 0;
	for (int i = 0; i <len; i++)
	{
		sum = sum + temp[i] * (1 << i);
	}
	return sum;
}


int main()
{
	int x = 86;
	int res = nextSparseNum(x);
	cout << res << endl;
	system("pause");
	return 1;
}