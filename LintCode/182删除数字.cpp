#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//182. ɾ������
//
//string DeleteDigits(string &A, int k)
//{
//	// write your code here
//	string res;
//	if (A.size() <= 0 || k > A.size())
//	{
//		return res;
//	}
//	int len = A.size();
//	vector<int> temp(len, 0);
//	//vector<int> temp1(len, 0);
//	for (int i = 0; i < len; i++)
//	{
//		temp[i] = A[i] - '0'; //���ַ�����ת��Ϊ���֡�
//		//temp1[i] = A[i] - '0';
//	}
//	//�ҵ�����ǰKλ��������������Ϊ-1;
//	while (k--)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			if (temp[j] <= temp[j + 1])
//			{
//				j++;
//				temp[j] = -1;
//				break;
//			}
//		}
//	}
//	int count = len - k;
//	res.resize(count);//�����ַ���������Ч���ȡ�
//	int j = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (temp[i] == -1)
//		{
//			continue;
//		}
//		temp[i] = temp[i] + '0';//������ת�����˶�Ӧ���ַ��������Ӧ��ASCII
//		res[j] = (char)temp[i];//ת�����ַ����֡�
//		j++;
//	}
//	int m;
//	for (m = 0; res[m] == '0'; ++m);//�ҵ���һ����Ϊ0��λ�á�
//    return  res.substr(m);
//}

//�����ύ����� 96.80% ���ύ!
string DeleteDigits(string &A, int k)
{
	// write your code here
	string ret;
	if(A.empty())
	   return ret;
	ret = A;
	while(k--)
	{
		int i = 0;
		while (i < ret.length() - 1 && ret[i] <= ret[i + 1])
			++i;
		ret = ret.substr(0, i) + ret.substr(i + 1);
	}
	int i;
	for (i = 0; ret[i] == '0'; ++i);//�ҵ���һ����Ϊ0��λ�á�
	ret = ret.substr(i);
	return ret;
}



int main()
{
	string str = "178542";
	int k = 4;
	string res = DeleteDigits(str, 4);
	cout << res << endl;
	system("pause");
	return 1;
}