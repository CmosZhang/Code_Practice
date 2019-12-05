#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;


//78. �����ǰ׺
//�����ύ����� 100.00% ���ύ!
string longestCommonPrefix(vector<string> &strs)
{
	// write your code here
	string res;
	if (strs.empty())
	{
		return res;
	}
	int len = strs.size();
	for (int i = 0; i < strs[0].size(); i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (strs[j][i] != strs[0][i])
			{
				return strs[0].substr(0, i);
			}
		}
	}
	return strs[0];
}

//171. �����ַ���
//�����ύ����� 90.60% ���ύ!
vector<string> anagrams(vector<string> &strs)
{
	// write your code here
	vector<string> res;
	if (strs.empty())
	{
		return res;
	}
	//����hash��˼�롣
	map<string, int> m;
	for (auto s : strs)
	{
		sort(s.begin(), s.end());
		m[s]++;
	}
	for (auto s : strs) 
	{ 
		auto temp = s; 
		sort(temp.begin(), temp.end());
		if (m[temp] > 1)
		{
			res.push_back(s);
			//����push_back(temp),temp�Ѿ���˳������
		}
	}
	return res;
}

//79. ������Ӵ�
//�����ύ����� 85.60% ���ύ!
int longestCommonSubstring(string &A, string &B)
{
	// write your code here
	int Alen = A.size();
	int Blen = B.size();
	if (Alen == 0 || Blen == 0)
	{
		return 0;
	}
	int max = 0;
	for (int i = 0; i < Alen; i++)
	{
		for (int j = 0; j < Blen; j++)
		{
			int m = i, n = j;
			int len = 0;
			while (m < Alen && n < Blen)
			{
				if (A[m] != B[n])
				{
					break;
				}
				m++;
				n++;
				len++;
			}
			if (len > max)
			{
				max = len;
			}
		}
	}
	return max;
}

int main()
{
	//vector<string> strs = {"ABCD"};
	//string s;
	//s = longestCommonPrefix(strs);
	//cout << s << endl;

	//vector<string> strs2 = { "lint","intl","inlt","code" };
	//vector<string> res2 = anagrams(strs2);
	//for (int i = 0; i < res2.size(); i++)
	//{
	//	cout << res2[i] << " ";
	//}
	//cout << endl;

	string A = { "ABCDAAAB" };
	string B = { "CBCEAAAC" };
	int num = longestCommonSubstring(A, B);
	cout << num << endl;
	system("pause");
	return 1;
}