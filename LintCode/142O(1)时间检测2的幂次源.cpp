#include<iostream>

using namespace std;

//142. O(1)ʱ����2���ݴ�
//�����ύ����� 88.00% ���ύ!
bool checkPowerOf2(int n)
{
	// write your code here
	if (n < 1)
	{
		return false;
	}
	return n & (n - 1) == 0;
}

int main()
{
	int a = 5;
	bool flag = checkPowerOf2(a);
	cout << flag << endl;
	system("pause");
	return 1;
}