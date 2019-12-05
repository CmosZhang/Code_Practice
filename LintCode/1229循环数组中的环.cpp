#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//1229. ѭ�������еĻ�
//�������
//�����ύ����� 98.31% ���ύ!
bool circularArrayLoop(vector<int> &nums) {
	// Write your code here
	if (nums.empty())
	{
		return false;
	}
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == 0)
		{
			continue;
		}
		int cur = nums[i];
		nums[i] = 0;//�����λ�ó�������󷵻����λ�õ�ʱ�򣬾Ͳ���Ҫ�ټ�������λ�ó����Ƿ�����γɻ���Ҫ����һֱѭ����ȥ
		//�ƶ�������һ��λ��
		int next = (i + cur + len) % len;
		if (next == i)//û�з����ƶ�
		{
			continue;
		}
		while (cur*nums[next] > 0)//����Ҫ�̶���Ҫôһֱ����Ҫôһֱ����
		{
			cur = nums[next];
			nums[next] = 0;//������ͬ���ĵ���
			next = (cur + next + len) % len;
		}
		if (next == i)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 2,-1,1,2,2};
	cout << circularArrayLoop(nums) << endl;
	system("pause");
	return 0;
}