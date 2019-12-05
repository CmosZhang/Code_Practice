#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//187. ����վ
//�����ύ����� 95.20% ���ύ!
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
	// write your code here
	if (gas.empty() || cost.empty())
		return 0;
	int n = cost.size();
	int begin = 0;        //����ӵ��������վ��ʼ��
	int cur = 0;          //��ǰ������
	int Gas = 0, Cost = 0;  //Gas��¼����������Cost��¼�����껷·����������
	for (int i = 0; i < n; ++i)
	{
		cur += gas[i];   //������
		cur -= cost[i];  //�ߵ���һվ�Ļ���
		Gas += gas[i];
		Cost += cost[i];
		if (cur < 0)
		{     //�ӵ�ǰ����վ�߲�����һվ
			begin = i + 1; //�滻�����㣬��ʵ����һ��һ���ԣ�������1��n
			cur = 0;     //���¼���
		}
	}
	return Gas >= Cost ? begin : -1;   //������������������������϶��߲����ˣ�����ͷ�����ʼ��
}



int main()
{
	vector<int>A = { 1, 1, 3, 1 };
	vector<int>B = { 2, 2, 1, 1 };
	int res = canCompleteCircuit(A, B);
	cout << res << endl;
	system("pause");
	return 0;
}