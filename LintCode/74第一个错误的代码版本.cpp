#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//74. ��һ������Ĵ���汾
//����汾�Ĵ���Time Limit Exceeded
//ԭ�򣺷�ֹStack Overflow������low �� high ���ܴ�
//��������int��value range���棩����������ܴ�������Ϳ��ܻᳬ��2,147,483,647��
//���ĺ������ύ����� 28.40% ���ύ!
//����������в��ˡ�SVNRepo::isBadVersion(mid)�������û�С�
int findFirstBadVersion(int n)
{
	// write your code here
	if (n <= 0)
	{
		return n;
	}
	int low = 1;
	int high = n;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;//�ⲻ��д�� mid=(low+high)/2
		if (SVNRepo::isBadVersion(mid) == true)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}


int main()
{


	system("pause");
	return 1;
}