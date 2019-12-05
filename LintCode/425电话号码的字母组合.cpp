#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

//425. �绰�������ĸ���
//����һ��ʹ��map����
//�����ύ����� 88.40% ���ύ!
void dfs(vector<string>&res, string digits, unordered_map<char, string>&TelNum, string temp)
{
	if (digits.size() == 0)
	{
		if (temp != "")
		{
			res.push_back(temp);
		}
	}
	int len = TelNum[digits[0]].size();
	for (int i = 0; i<len; i++) 
	{
		dfs(res, digits.substr(1), TelNum, temp + TelNum[digits[0]][i]);
	}
}

vector<string> letterCombinations(string &digits)
{
	// write your code here
	vector<string> res;
	if (digits.size() <= 0)
	{
		return res;
	}
	unordered_map<char, string> TelNum;
	//����map
	TelNum.insert(pair<char, string>('0', ""));
	TelNum.insert(pair<char, string>('1', ""));
	TelNum.insert(pair<char, string>('2', "abc"));
	TelNum.insert(pair<char, string>('3', "def"));
	TelNum.insert(pair<char, string>('4', "ghi"));
	TelNum.insert(pair<char, string>('5', "jkl"));
	TelNum.insert(pair<char, string>('6', "mno"));
	TelNum.insert(pair<char, string>('7', "pqrs"));
	TelNum.insert(pair<char, string>('8', "tuv"));
	TelNum.insert(pair<char, string>('9', "wxyz"));

	//ʹ�û��ݷ�����
	string temp = "";
	dfs(res, digits, TelNum, temp);
	return res;
}

////������
////�����ύ����� 65.20% ���ύ!
//vector<string> letterCombinations(string &digits) 
//{
//	// write your code here
//	vector<string> result;
//	if (digits.size() <= 0) 
//	{
//		return result;
//	}
//	string str;
//	letterCombinations(digits, str, 0, result);
//	return result;
//}
//
//void letterCombinations(string &digits, string &str, int index, vector<string> &result) 
//{
//	if (index == digits.size()) 
//	{
//		result.push_back(str);
//		return;
//	}
//	string base[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//	for (int i = 0; i < base[digits[index] - '0'].size(); i++) 
//	{
//		str += base[digits[index] - '0'][i];
//		letterCombinations(digits, str, index + 1, result);
//		str.pop_back();
//	}
//}

//int main()
//{
//	char str[10] = "output";
//	printf("\"%s\"\n", str);
//	system("pause");
//	return 0;
//}
//void Func(char str_arg[2])
//{
//	int m = sizeof(str_arg);
//	int n = strlen(str_arg);
//	printf("%d\n", m);
//	printf("%d\n", n);
//}
//int main(void)
//{
//	char str[] = "Hello";
//	Func(str);
//	system("pause");
//	return 0;
//}
