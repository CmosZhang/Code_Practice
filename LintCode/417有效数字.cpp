#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//417. ��Ч����
//�����ύ����� 98.80% ���ύ!
//���ǵ�����ࡣ
bool isNumber(string &s) 
{
	// write your code here
	if (s.size() <= 0)
	{
		return false;
	}
	int len = s.size();
	//ȥ��ͷ���Ŀո�
	int start = 0;
	while (start < len&&s[start] == ' ')
	{
		start++;
	}
	if (start == len)
	{
		return false;   //�ַ���ȫ�ǿո�
	}
	bool flag_dian = false; //�ж�С���㡣
	bool flag_e = false; //�жϿ�ѧ������e��
	bool flag_blank = false; //�жϿո�
	//����������
	if (s[start] == '+' || s[start] == '-')
	{
		start++;
	}
	if (s[start] == '.')
	{
		flag_dian = true;
		start++;
	}
	if (!(s[start] >= '0' && s[start] <= '9'))//��һ���ַ�����������
	{
		return false;
	}
	while (start < len)
	{
		if (s[start] >= '0'&&s[start] <= '9')
		{
			start++;
		}
		else if (!flag_blank&&s[start] == ' ') //������ֿո񣬿ո�Ҫ������������
		{
			while (s[start] == ' '&&start < len)
			{
				start++;
			}
			if (start == len)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (!flag_dian && !flag_e&&s[start] == '.')//����. ��֮ǰ������e.
		{
			flag_dian = true;
			start++;
		}
		else if (!flag_e&&s[start] == 'e')
		{
			flag_e = true;
			start++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s = "0.1";
	bool flag = isNumber(s);
	cout << flag << endl;
	system("pause");
	return 1;
}