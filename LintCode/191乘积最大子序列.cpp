#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

//191. �˻����������
//�����ύ����� 85.80% ���ύ!
//Ҫ������
//ʹ�ö�̬�滮�㷨
int maxProduct(vector<int> &nums) 
{
	// write your code here
	if (nums.empty())
	{
		return -1;
	}
	int len = nums.size();
	int maxValue = nums[0];
	int minValue = nums[0];
	int ans = nums[0];
	for (int i = 1; i < len; i++)
	{
		int maxTemp = maxValue;
		int minTemp = minValue;
		maxValue = max(nums[i], max(maxTemp*nums[i], minTemp*nums[i]));
		minValue = min(nums[i], min(maxTemp*nums[i], minTemp*nums[i]));
		ans = max(ans,maxValue);
	}
	return ans;
}

int main()
{
	vector<int> nums = {-4,-3,-2};
	int res = maxProduct(nums);
	cout << res << endl;
	system("pause");
	return 0;
}