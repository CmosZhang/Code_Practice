#include<iostream>
#include<string>

using namespace std;

//������ַ����д�Сд�����֣��������õ�ӳ���Ϊ58.Сд��ĸz���д��ĸA��ASCII���57.
//����ӳ���Ĵ�СӦ����58.
bool anagram(string &s, string &t)
{
	// write your code here
	if (s.size() <= 0 || t.size() <= 0)
	{
		return false;
	}
	int dic[58] = { 0 };
	int index;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		index = s[i] - 'A';
		dic[index]++;
	}
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == ' ')
			continue;
		index = t[i] - 'A';
		dic[index]--;
	}
	for (int k = 0; k < 58; k++)
	{
		if (dic[k] != 0)
		{
			return false;
		}
	}
	return true;
}
