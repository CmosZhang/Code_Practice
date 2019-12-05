#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>


using namespace std;

bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
	{
		return true;
	}
	return false;
}


//1282. ��ת�ַ����е�Ԫ����ĸ
string reverseVowels(string &s) 
{
	// write your code here
	if (s.size() <= 0)
	{
		return s;
	}
	stack<char>vowel;
	for (int i = 0; i < s.size(); i++)
	{
		if (isVowel(s[i]))
		{
			vowel.push(s[i]);//��ջ
			s[i] = NULL;
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == NULL)
		{
			s[i] = vowel.top();//ȡջ��
			vowel.pop();//��ջ
		}
	}
	return s;
}

int main()
{
	string s, s1;
	getline(cin, s);
	s1 = reverseVowels(s);
	cout << s1 << endl;
	system("pause");
	return 1;
}