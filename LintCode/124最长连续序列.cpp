#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

//124��������С����100%���ύ��
int longestConsecutive(vector<int> &num)
{
	// write your code here
	if (num.size() <= 0)
	{
		return 0;
	}
	int len = num.size();
	sort(num.begin(), num.end());//�����
	int count = 1;
	int length = 1;
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len&&num[i] + 1 == num[i + 1])//�ж�������
		{
			length++;//������������Ļ���������̶���2.����length�ĳ�ʼֵҪ����Ϊ1. 
			count = max(length, count);//�ж�����������У��ҵ��������С�
		}
		else if (i + 1 < len&&num[i] == num[i + 1])//�����ظ�Ԫ��
		{
			continue;
		}
		else
		{
			length = 1;
		}
	}
	return count;
}

int main()
{
	vector<int>nums = {1,3,2,4,3,2,3};
	int res = longestConsecutive(nums);
	cout << res << endl;
	system("pause");
	return 1;
}