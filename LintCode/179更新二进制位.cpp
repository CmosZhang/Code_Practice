#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//179. ���¶�����λ
//�����ύ����� 97.40% ���ύ!
int updateBits(int n, int m, int i, int j) 
{
	// write your code here
	for (int k = 0; i <= j; ++i, ++k) 
	{
		if (m&(1 << k))  //�ж�m�ĵ�kλ�Ƿ�Ϊ1  
			n|=1<<i;  //���Ϊ1��n�ĵ�iλ��1 
		else               
			n&=~(1<<i);//�����iλ��0 
	}        
	return n;
}


int main()
{
	int n = 1024, m = 21, i = 2, j = 6;
	int res = updateBits(n, m, i, j);
	cout << res << endl;
	system("pause");
	return 1;
}