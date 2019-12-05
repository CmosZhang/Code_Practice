#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//656. �������˷�
//�����ύ����� 97.20% ���ύ!
string multiply(string &num1, string &num2)
{
	// write your code here

	string res(num1.size() + num2.size(), '0');

	string shorter = num1.size() < num2.size() ? num1 : num2;
	string longer = num1.size() < num2.size() ? num2 : num1;
	
	for (int i = shorter.size() - 1; i >= 0; --i)
	{
		int carry = 0;//��λ
		for (int j = longer.size() - 1; j >= 0; --j)
		{
			int temp = (longer[j] - '0')*(shorter[i] - '0') + carry + res[i + j + 1] - '0';
			res[i + j + 1] = temp % 10 + '0';
			carry = temp / 10;
			if (carry&&j == 0)//����̴��Ѿ��������(j==0)����carry�ǲ�Ϊ0�ģ���ôresҪ�޸ģ�
				res[i] += carry;
		}
	}
	//ȥ��ǰ�ŵ�0
	int i = 0;
	while (res[i] == '0')//�˴���Ҫдi++;
		res.erase(0, 1);
	return res.size() == 0 ? "0" : res;
}