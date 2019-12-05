#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//570. Ѱ�Ҷ�ʧ���� II
//ʹ�û��ݵķ�������
//�����ύ����� 74.60% ���ύ!
int findTheNum(vector<int>&d, int index, string &str)
{
	int res = -1;
	if (index == str.size() && d[0] == d.size() - 2)
	{//������Ҫ�ĳ��ڣ���index����str������һ��λ�ò������������ﵽn-1��ʱ����ʣ�����
		for (int i = 1; i < d.size(); i++)
		{
			if (d[i] == 0)
			{
				res = i;
			}
		}
	}
	if (str[index] == '0')//ָ�����һ������0��ʼֱ�ӷ���
	{
		return res;
	}
	else
	{
		int temp1 = str[index] - '0';//��һ������
		if (d[temp1] == 0)
		{
			d[temp1] = 1;//������������ҵ����ʵĽ��
			d[0]++;//����+1
			int ret = findTheNum(d, index + 1, str);
			if (ret != -1)
				res = ret;//������ҵ�����resֵ
			d[temp1] = 0;//���ݵ���·���ָ�ԭ״
			d[0]--;
		}
		if (index + 1 < str.size())
		{
			int temp2 = str[index + 1] - '0';
			temp2 = temp2 + temp1 * 10;//������������
			if (temp2 < d.size() && d[temp2] == 0)
			{
				d[temp2] = 1;
				d[0]++;
				int ret = findTheNum(d, index + 2, str);
				if (ret != -1)
					res = ret;
				d[temp2] = 0;
				d[0]--;
			}
		}
	}
	return res;//�������Ľ��
}

int findMissing2(int n, string &str) {
	// write your code here
	if (str.empty() || n < 1)
	{
		return 0;
	}
	vector<int> dict(n + 1, 0);//�������ڱ�������Ƿ���ֹ���dict[0]������¼�Ѿ������˶��ٸ�����
	return findTheNum(dict, 0, str);
}


//�ڶ��ַ���
//�����ύ����� 75.60% ���ύ!
void search(int n, string &str, int index[], vector<bool>&exist, int len)
{
	if(index[0]>=len)
	{
		return;
	}
	if (str[index[0]] == '0')
	{
		return;
	}
	if (!exist[str[index[0]] - '0'])
	{
		exist[str[index[0]] - '0'] = true;
		index[0]++;
		search(n, str, index, exist, len);
		if (index[0] >= len)
			return;
		index[0]--;
		exist[str[index[0]] - '0'] = false;
	}
	if (index[0] < len - 1)
	{
		int a = str[index[0]] - '0';
		int b = str[index[0] + 1] - '0';
		int value = 10 * a + b;
		if (value <= n && !exist[value])
		{
			exist[value] = true;
			index[0] += 2;
			search(n, str, index, exist, len);
			if (index[0] >= len)
				return;
			index[0] -= 2;
			exist[value] = false;
		}
	}
}

int findMissing2(int n, string &str)
{
	if (n < 1 || str.empty())
	{
		return 0;
	}
	int len = str.size();
	vector<bool> exist(n + 1, false);
	int index[] = { 0 };
	search(n, str, index, exist, len);
	for (int i = 1; i <= len; i++)
	{
		if (!exist[i])
		{
			return i;
		}
	}
	return 0;
}


int main()
{
	string str = "19201234567891011121314151618";
	int n = 20;
	cout << findMissing2(n, str) << endl;
	system("pause");
	return 0;
}