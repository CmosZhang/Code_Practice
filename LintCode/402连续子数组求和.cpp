#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//402. �������������
//�����ύ����� 100.00% ���ύ!
vector<int> continuousSubarraySum(vector<int> &A) {
	// write your code here
	if (A.empty()) {
		return A;
	}
	int len = A.size();vecto
	vector<int> dp(len);
	vector<int> res;
	res.push_back(0);
	res.push_back(0);
	int n = A.size();
	int res_sum = A[0]; // ��ǰ������ĺ�
	int sum = 0;        // ö�ٹ���������ĺ�
	int l = 0;          // ö�ٹ�����������˵�
	for (int r = 0; r < n; r++)
	{
		if (sum < 0)    // ���ǰ����������ĺ�С��0, ��ô��rΪ�Ҷ˵�����;��� A[r]
		{
			l = r;
			sum = A[r];
		}
		else
			sum += A[r];
		if (sum > res_sum)  // ���´�����: �����ǰ����ʹ��ڴ�����
		{
			res_sum = sum;
			res[0] = l;
			res[1] = r;
		}
	}
	return res;
}