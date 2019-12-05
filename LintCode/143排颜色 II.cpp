#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//143. ����ɫ II
//ʹ�ÿ��ţ�����k�Ĵ���
//�����ύ����� 25.40% ���ύ!
//ʱ�临�Ӷ�ΪO(nlogn)
//void sortColors2(vector<int> &colors, int k)
//{
//	// write your code here
//	sort(colors.begin(), colors.end());
//}

//ʹ�ü�������
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(k)
//�����ύ����� 100.00% ���ύ!
void sortColors2(vector<int> &colors, int k)
{
	// write your code here
	vector<int> count(k + 1, 0);
	for (int i = 0; i < colors.size(); i++)
	{
		count[colors[i]]++;
	}

	int index = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			colors[index] = i;
			index++;
		}
	}
}