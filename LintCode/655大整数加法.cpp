#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//655. 大整数加法
//您的提交打败了 78.40% 的提交!
string addStrings(string &num1, string &num2)
{
	// write your code here
	string res = "";

	//先将两个数弄成长度一致
	if (num1.size() < num2.size())
	{
		num1 = string(num2.size() - num1.size(), '0') + num1;
	}
	else
	{
		num2 = string(num1.size() - num2.size(), '0') + num2;
	}
    //进位
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i)//个位在最后面
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

//655. 大整数减法
string subStrings(string &num1, string &num2)
{
	// write your code here
	//默认num1 比num2 大，num1 是减数，num2 是被减数
	string res = "";

	//先将两个数的长度一致
	if (num1.size() < num2.size())
	{
		return res;
	}
	else
	{
		num2 = string(num1.size() - num2.size(), '0') + num2;
	}
	//借位
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i)//个位在最后面
	{
		carry = 0;
		int temp = (num1[i] - '0' - num2[i] + '0' + carry * 10) % 10;
		if (temp >= 0)//没有借位
		{
			char c_temp = temp + '0';
			res = c_temp + res;
			//cout << res << endl;
		}
		else//产生借位情况
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
	//去掉前排的0
	int i = 0;
	while (res[i] == '0')//此处不要写i++;
		res.erase(0, 1);
	return res;
}

//格式转换，先把大数加法的输入统一成不带任何前缀符号的，去掉‘+’
void TransPattern(string &num1, string &num2)
{
	//两个都是负数
	if (num1[0] == '+')
	{
		num1.substr(1);
	}
	if (num2[0] == '+')
	{
		num2.substr(1);
	}
}

//符号不统一时，做减法，默认num1是减数，num2是被减数
bool SubPattern(string &num1, string &num2)
{
	bool flag = true;//最后结果为正
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

//要考虑到负数的情况，负+正，正+负，正+正，负+负
//默认输入不会有+
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
		bool flag = true;//判断正负数
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
		bool flag = SubPattern(num1, num2);//判断最后的结果是正是负

		//这种情况下，是一正一负来进行操作，相当于是减法
		//默认num1 比num2 大，num1 是减数，num2 是被减数
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