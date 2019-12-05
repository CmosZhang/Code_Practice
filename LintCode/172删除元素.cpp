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
//			//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
//			it = A.erase(it);
//		else
//			//迭代器指向下一个元素位置
//			++it;
//	}
//	return A.size();
//}

// 简单方法
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