#include <iostream>
#include <string>
#include<algorithm>

using namespace std;



string sum(string strLong1, string strLong2, string strShort1, string strShort2)
{
	if (strLong2.size() < strShort2.size()) {
		string strTemp = strLong2;
		strLong2 = strShort2;
		strShort2 = strTemp;
	}
	for (int i = strShort2.size(); i < strLong2.size(); ++i)
		strShort2 += '0';
	reverse(strLong2.begin(), strLong2.end());
	reverse(strShort2.begin(), strShort2.end());
	string strRes2(strLong2.size(), '0');
	int carry = 0;
	for (int i = 0; i != strLong2.size(); ++i) {
		int a = strShort2[i] - '0', b = strLong2[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes2[i] = (a % 10) + '0';
	}
	reverse(strRes2.begin(), strRes2.end());
	if (strLong1.size() < strShort1.size()) {
		string strTemp = strLong1;
		strLong1 = strShort1;
		strShort1 = strTemp;
	}

	reverse(strLong1.begin(), strLong1.end());
	reverse(strShort1.begin(), strShort1.end());
	string strRes1(strLong1.size(), '0');
	for (int k = 0; k != strShort1.size(); ++k) {
		int a = strShort1[k] - '0', b = strLong1[k] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes1[k] = (a % 10) + '0';
	}
	for (int k = strShort1.size(); k != strLong1.size(); ++k) {
		int b = strLong1[k] - '0';
		b += carry;
		carry = b / 10;
		strRes1[k] = b % 10 + '0';
	}
	if (carry) {
		strRes1 += (carry + '0');
	}
	reverse(strRes1.begin(), strRes1.end());
	string strRes = strRes1 + '.' + strRes2;
	return strRes;
}

string getResult(string num1, string num2) {

	string num11, num12, num21, num22;
	bool num1Flag = false, num2Flag = false;
	for (auto c : num1)
	{
		if (!isdigit(c) || num1.empty())
		{
			if (c == '.' && !num1Flag)
			{
				num1Flag = true;
			}
		}
	}

	for (auto c : num2) {
		if (!isdigit(c) || num2.empty()) {
			if (c == '.' && !num2Flag) {
				num2Flag = true;
			}
		}
	}

	if (num1Flag) {
		int k = 0, i = 0;
		while (k != num1.size() && num1[k] != '.')
		{
			num11 += num1[k];
			++k;
		}
		while (++k != num1.size())
		{
			num12 += num1[k];
		}
		if (num11.empty())
			num11 += '0';
		if (num12.empty())
			num12 += '0';
	}
	else {
		num11 = num1;
		num12 += '0';
	}
	if (num2Flag) {
		int k = 0;
		int j = 0;
		bool flag = true;
		while (k != num2.size() && num2[k] != '.')
		{
			num21 += num2[k];
			++k;
		}
		while (++k != num2.size())
		{
			num22 += num2[k];
		}
		if (num21.empty())
			num21 += '0';
		if (num22.empty())
			num22 += '0';
	}
	else
	{
		num21 = num2;
		num22 += '0';
	}
	string str = sum(num11, num12, num21, num22);
	return str;
}


string add(string& a1, string& a2) {

	// please write your code here.
	string res = getResult(a1, a2);

	int pos = res.find_first_of('.');
	int zero = res.find_last_not_of('0');
	if (pos == zero) {
		res = res.substr(0, pos);
	}
	return res;
}

// please don't modify any code below.
int main(void) {
	string a1, a2, a3;
	cin >> a1 >> a2;
	a3 = add(a1, a2);
	cout << a3 << endl;
	return 0;
}
