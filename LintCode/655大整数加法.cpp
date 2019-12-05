#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//655. �������ӷ�
//�����ύ����� 78.40% ���ύ!
string addStrings(string &num1, string &num2)
{
	// write your code here
	string res = "";

	//�Ƚ�������Ū�ɳ���һ��
	if (num1.size() < num2.size())
	{
		num1 = string(num2.size() - num1.size(), '0') + num1;
	}
	else
	{
		num2 = string(num1.size() - num2.size(), '0') + num2;
	}
    //��λ
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i)//��λ�������
	{
		char temp = (num1[i] - '0' + num2[i] - '0' + carry) % 10 + '0';
		res = temp + res;
		//cout << res << endl;
		carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
	}
	if (carry)   
		res = '1' + res;
	return res;
}

//655. ����������
string subStrings(string &num1, string &num2)
{
	// write your code here
	//Ĭ��num1 ��num2 ��num1 �Ǽ�����num2 �Ǳ�����
	string res = "";

	//�Ƚ��������ĳ���һ��
	if (num1.size() < num2.size())
	{
		return res;
	}
	else
	{
		num2 = string(num1.size() - num2.size(), '0') + num2;
	}
	//��λ
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i)//��λ�������
	{
		carry = 0;
		int temp = (num1[i] - '0' - num2[i] + '0' + carry * 10) % 10;
		if (temp >= 0)//û�н�λ
		{
			char c_temp = temp + '0';
			res = c_temp + res;
			//cout << res << endl;
		}
		else//������λ���
		{
			num1[i - 1]--;
			carry = 1;
			temp = (temp + carry * 10) % 10;
			char c_temp = temp + '0';
			res = c_temp + res;
		}
		//cout << res << endl;
	}
	if (carry)
		res = res[0] - '1';
	//ȥ��ǰ�ŵ�0
	int i = 0;
	while (res[i] == '0')//�˴���Ҫдi++;
		res.erase(0, 1);
	return res;
}

//��ʽת�����ȰѴ����ӷ�������ͳһ�ɲ����κ�ǰ׺���ŵģ�ȥ����+��
void TransPattern(string &num1, string &num2)
{
	//�������Ǹ���
	if (num1[0] == '+')
	{
		num1.substr(1);
	}
	if (num2[0] == '+')
	{
		num2.substr(1);
	}
}

//���Ų�ͳһʱ����������Ĭ��num1�Ǽ�����num2�Ǳ�����
bool SubPattern(string &num1, string &num2)
{
	bool flag = true;//�����Ϊ��
	if (num1[0] != '-'&&num2[0] == '-')
	{
		string temp = num2;
		num2 = num1;
		num1 = temp;
	}
	num1 = num1.substr(1);
	if (num1.size() > num2.size())
	{
		flag = false;
		return flag;
	}
	else if (num1.size() == num2.size())
	{
		if (num1.compare(num2) > 0)
		{
			flag = false;
			return flag;
		}
		else if (num1.compare(num2) < 0)
		{
			string temp = num2;
			num2 = num1;
			num1 = temp;
		}
	}
	else
	{
		string temp = num2;
		num2 = num1;
		num1 = temp;
	}
	return flag;
}

bool CheckInput(string &num1)
{
	char c1 = num1[0];
	if (c1 == '-' || c1 == '+' || (c1 >= '0'&&c1 <= '9'))
	{
		return true;
	}
	return false;
}

//Ҫ���ǵ��������������+������+������+������+��
//Ĭ�����벻����+
string AddStrings(string &num1, string &num2)
{
	string res = "";
	if (num1.empty())
	{
		return num2;
	}
	if (num2.empty())
	{
		return num1;
	}
	if (CheckInput(num1) == false || CheckInput(num2) == false)
	{
		return res;
	}
	TransPattern(num1, num2);
	if (num1[0] != '-'&&num2[0] != '-' || num1[0] == '-'&&num2[0] == '-')
	{
		bool flag = true;//�ж�������
		if (num1[0] == '-'&&num2[0] == '-')
		{
			flag = false;
			num1 = num1.substr(1);
			num2 = num2.substr(1);
		}
		string res = addStrings(num1,num2);
		return flag == true ? res : '-' + res;
	}
	else
	{
		bool flag = SubPattern(num1, num2);//�ж����Ľ�������Ǹ�

		//��������£���һ��һ�������в������൱���Ǽ���
		//Ĭ��num1 ��num2 ��num1 �Ǽ�����num2 �Ǳ�����
		string res = subStrings(num1, num2);
		return flag == true ? res : '-' + res;
	}
}


int main()
{
	string num1 = "923";
	string num2 = "-9990";
	string res = AddStrings(num1,num2);
	cout << res << endl;
	system("pause");
	return 0;
}