#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;


//362. �������ڵ����ֵ
//90% ����ͨ������
//ʱ�临�Ӷ�̫�ߡ�
//��ţ����������ȫ��ͨ����
//vector<int> maxSlidingWindow(vector<int> &nums, int k)
//{
//	// write your code here
    //vector<int> res;
	//if (nums.empty() || nums.size() < k|| k <= 0 )
	//{
	//	return res;
	//}
	//int len = nums.size();
	//for (int i = 0; i <= len - k; i++)
	//{
	//	int max = INT_MIN;
	//	for (int j = 0; j < k; j++)
	//	{
	//		if (nums[i + j] > max)
	//		{
	//			max = nums[i + j];
	//		}
	//	}
	//	res.push_back(max);
	//}
	//return res;
//}

//�����ύ����� 65.20% ���ύ!
//����˫���������
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
	vector<int> res;
	if (nums.empty() || nums.size() < k || k <= 0)
	{
		return res;
	}
	int len = nums.size();
	deque<int> index;
	for (int i = 0; i < len; i++)
	{
		//�Ӷ��к��浯���ȵ�ǰԪ��С�ĵ�ֵ
		while (index.empty() != true && nums[i] >= nums[index.back()])
		{
			index.pop_back();
		}
		if(index.empty() != true && index.front() <= i - k)//����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ����
		{
			index.pop_front();
		}
		index.push_back(i);//��ÿ�λ�����nums�±�������
		if (i + 1 >= k)//�����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ
		{
			res.push_back(nums[index.front()]);
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,2,7 ,7,8};
	int k = 3;
	vector<int> res = maxSlidingWindow(nums, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}