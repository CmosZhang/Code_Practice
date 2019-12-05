#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//723. ����ת������λ
//�����ύ����� 94.41% ���ύ!
int leftRotate(int n, int d)
{
	// write code here
	vector<int> temp;
	for (int i = 0; i < 32; i++)
	{

		int count = (n >> i) & 1;
		temp.push_back(count);
	}
	//ע�ⷴת������ת�Ļ����Ǵӵ�λ����λ��
	reverse(temp.begin(), temp.end());//n��32λ�����ƴ洢���Ӹ�λ����λ��
	//����
	vector<int> res = temp;
	for (int i = 0; i < 32; i++)
	{
		if (i < 32 - d)
		{
			res[i] = temp[i + d];
		}
		else
		{
			res[i] = temp[i + d - 32];
		}
	}
	//����������ת����ʮ���ơ�
	//long long��ֹ�����
	long long sum = 0;
	for (int i = 31; i >= 0; i--)
	{
		sum = sum + res[i] * pow(2, 31 - i);
	}
	return sum;
}

int main()
{
	int n = 123, d = 4;
	int res = leftRotate(n, d);
	cout << res << endl;
	system("pause");
	return 1;
}