#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//int removeElement(vector<int> &A, int elem)
//{
//	// write your code here
//	if (A.size() <= 0)
//	{
//		return 0;
//	}
//	vector<int>::iterator it = A.begin();
//	for (; it != A.end();)
//	{
//		if (*it == elem)
//			//ɾ��ָ��Ԫ�أ�����ָ��ɾ��Ԫ�ص���һ��Ԫ�ص�λ�õĵ�����
//			it = A.erase(it);
//		else
//			//������ָ����һ��Ԫ��λ��
//			++it;
//	}
//	return A.size();
//}

// �򵥷���
int removeElement(vector<int> &A, int elem)
{
	// write your code here
	if (A.size() <= 0)
	{
		return 0;
	}
	int j = 0;
	for (int i = 0; i<A.size(); i++)
	{
		if (A[i] != elem)
		{
			A[j] = A[i];
			j++;
		}
	}
	return j;
}



int main()
{
	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	int num = 3;
	int res = removeElement(vec,3);
	cout << res << endl;
	system("pause");
	return 1;
}