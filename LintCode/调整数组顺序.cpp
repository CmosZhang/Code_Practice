#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//��ĿҪ��
//������0������������������棬������0����������������ǰ�棬��������������
//˼·���Ƚ�0�ŵ����棬Ȼ�����ǰ������ֽ��п���


void partitionArray(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return;
	}
	int len = nums.size();
	int start = 0;
	int end = len - 1;
	while (start<end)
	{
		while (nums[start] != 0 && start < end)
		{
			start++;
		}
		while (nums[end] == 0 && start < end)
		{
			end--;
		}
		if (start < end)
		{
			swap(nums[start], nums[end]);
		}
	}
	sort(nums.begin(), nums.begin() + start);//��һ�����Ի����Լ�д�Ŀ���
}


int main()
{
	vector<int> nums = { 5,3,2,4,0,5,0,8,2,0,1,0,9 };
	partitionArray(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}