#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<strstream>

using namespace std;


//180. �����Ʊ�ʾ
//
string itoa(int n) 
{
	strstream ss;
	string s;
	ss << n;
	ss >> s;
	return s;
}
string binaryRepresentation(string &n)
{
	// write your code here
	string res;
	if (n.size() <= 0)
	{
		return res;
	}
	int len = n.size();
	//��������
	int intpart = atoi(n.substr(0,n.find(".")).c_str());
	//С������
	double decpart = atof(n.substr(n.find("."), len - n.find(".")).c_str());

	//��������ת���ɶ�����
	string int_string;
	while (intpart)
	{
		int r = intpart % 2;
		intpart >>= 1;
		int_string = itoa(r) + int_string;
	}
	if (int_string.size() == 0)
	{
		int_string = "0";
	}
	//С��������0
	if (n.substr(n.find("."),len - n.find(".")) == ".0")
	{
		return int_string;
	}

	//С������ת���ɶ�����
	string dec_string;
	while (decpart > 0)
	{
		if (dec_string.size() > 32)
		{
			return "ERROR";
		}
		if (decpart == 1)
		{
			dec_string += itoa(1);
			break;
		}
		double r = decpart * 2;
		if (r >= 1)
		{
			dec_string += "1";
			decpart = r - 1;
		}
		else 
		{
			dec_string += "0";
			decpart = r;
		}
	}
	return int_string + "." + dec_string;
}

int main()
{
	string str = "3.72";
	string res = binaryRepresentation(str);
	cout << res << endl;
	system("pause");
	return 1;
}