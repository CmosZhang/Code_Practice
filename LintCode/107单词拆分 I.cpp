#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<unordered_set>

using namespace std;

//107. ���ʲ�� I
//�����ύ����� 98.80% ���ύ!
bool wordBreak(string &s, unordered_set<string> &dict) 
{
	// write your code here
	if (s.empty() && dict.empty())
	{
		return true;
	}
	if (s.empty() || dict.empty())
	{
		return false;
	}

	//�ҵ�����Ӵ�
	int maxDict = 0;
	for (string str : dict)
	{
		if (str.length()>maxDict) 
		{
			maxDict = str.length();
		}
	}
	int len = s.length();
	bool *canSegment = new bool[len + 1];
	canSegment[0] = true;
	for (int i = 1; i <= len; i++)
	{
		canSegment[i] = false;
		for (int lastwordlength = 1; lastwordlength <= maxDict&&lastwordlength <= i; lastwordlength++)
		{
			if (!canSegment[i - lastwordlength])
			{
				continue;
			}
			string word = s.substr(i - lastwordlength, lastwordlength);
			if (dict.find(word) != dict.end()) 
			{
				canSegment[i] = true;
				break;
			}
		}
	}
	return canSegment[len];
}