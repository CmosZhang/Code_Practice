#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//82. �䵥����
//�����ύ����� 97.00% ���ύ!
int singleNumber(vector<int> &A)
{
	// write your code here
	if (A.size() <= 0)
	{
		return -1;
	}
	int len = A.size();
	int ans = A[0];
	for (int i = 1; i < len; i++)
	{
		ans = ans ^ A[i];
	}
	return ans;
}