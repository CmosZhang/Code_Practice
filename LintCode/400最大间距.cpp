#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

//400. �����
//�����ύ����� 75.40% ���ύ!
//ʹ������ķ��������ܼ�
/*
int maximumGap(vector<int> &nums)
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return 0;
	}
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int maxGap = INT_MIN;
	for (int i = 1; i < len; i++)
	{
		if (maxGap < nums[i] - nums[i - 1])
		{
			maxGap = nums[i] - nums[i - 1];
		}
	}
	return maxGap;
}
*/


//�����Ե�ʱ��Ϳռ临�Ӷȵķ�������������
//ʹ��Ͱ����ķ���
//�����ύ����� 75.80% ���ύ!
int maximumGap(vector<int> &nums)
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return 0;
	}
	
	int len = nums.size();
	int minValue = INT_MAX, maxValue = INT_MIN;
	for (int i = 0; i<len; i++)
	{
		maxValue = max(maxValue, nums[i]);
		minValue = min(minValue, nums[i]);
	}

	
	int size = (maxValue - minValue) / len + 1;
	int bucket_nums = (maxValue - minValue) / size + 1;
	vector<int> bucketMax(bucket_nums, INT_MIN);
	vector<int> bucketMin(bucket_nums, INT_MAX);
	//Ͱ�ڲ�����ֻ������������һ�����ֵ��һ����Сֵ�������������ϸ��¡�������һ�Ų�Ҫ
	//�ҵ���ǰͰ����Сֵ��ǰһ��Ͱ�����ֵ���Ƚϼ���
	set<int> s;
	for (int i = 0; i<len; i++) 
	{
		int idx = (nums[i] - minValue) / size;
		bucketMin[idx] = min(bucketMin[idx], nums[i]);
		bucketMax[idx] = max(bucketMax[idx], nums[i]);
		s.insert(idx);//��set�в���Ԫ��
	}
	int pre = 0;
	int maxGap = 0;
	for (int i = 1; i < len; ++i)
	{
		if (!s.count(i)) 
			continue;//���Ҽ�key��Ԫ�ظ���
		maxGap = max(maxGap, bucketMin[i] - bucketMax[pre]);
		pre = i;
	}
	return maxGap;
}

int main()
{
	vector<int> nums = { 3,2,1,4,3 };
	int res = maximumGap(nums);
	cout << res << endl;
	system("pause");
	return 0;

}