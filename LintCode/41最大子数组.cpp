#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//41���������
int maxSubArray(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int length = nums.size();
	int maxValue = nums[0];
	int sum = nums[0];
	for (int i = 1; i < length; i++)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
		}
	}
	return maxValue;
}

//42���������2
//�����ύ����� 92.40% ���ύ!
int maxTwoSubArrays(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int length = nums.size();
	vector<int> left(length, 0);
	vector<int> right(length, 0);
	left[0] = nums[0];
	int maxValue = nums[0];
	int sum = nums[0];
	for (int i = 1; i < length; i++)
	{
		if (sum < 0) 
		{
			sum = nums[i];
		}
		else 
		{
			sum += nums[i];
		}
		if (sum > maxValue) 
		{
			maxValue = sum;
		}
		left[i] = maxValue;
	}
	//cout << maxValue << endl;
	right[length - 1] = nums[length - 1];
	maxValue = nums[length - 1];
	sum = nums[length - 1];
	for (int i = length - 2; i >= 0; i--)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
		}
		right[i] = maxValue;
	}
	
	int res = -0x3f3f3f3f;
	for (int i = 1; i<nums.size(); i++)
	{
		res = max(res, left[i - 1] + right[i]);
    }
    return res;
}


//44. ��С������
int minSubArray(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int length = nums.size();
	int minValue = nums[0];
	int sum = nums[0];
	for (int i = 1; i < length; i++)
	{
		if (sum > 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum < minValue)
		{
			minValue = sum;
		}
	}
	return minValue;
}


//45. ����������
//�����ύ����� 99.60% ���ύ!
//���á������������͡��Ĵ���,����������ұ����������������maxLeft����С������minLeft
//�ʹ�����������������������maxRight����С������minRight��
//Ȼ�����maxLeft��minRight�����minLeft��maxRight��������ɵó����������
int maxDiffSubArrays(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int length = nums.size();
	vector<int> maxleft(length, 0);
	vector<int> maxright(length, 0);
	maxleft[0] = nums[0];
	int maxValue = nums[0];
	int sum = nums[0];
	for (int i = 1; i < length; i++)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
		}
		maxleft[i] = maxValue;
	}
	//cout << maxValue << endl;
	maxright[length - 1] = nums[length - 1];
	maxValue = nums[length - 1];
	sum = nums[length - 1];
	for (int i = length - 2; i >= 0; i--)
	{
		if (sum < 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
		}
		maxright[i] = maxValue;
	}

	vector<int> minleft(length, 0);
	vector<int> minright(length, 0);
	minleft[0] = nums[0];
	int minValue = nums[0];
	sum = nums[0];
	for (int i = 1; i < length; i++)
	{
		if (sum > 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum < minValue)
		{
			minValue = sum;
		}
		minleft[i] = minValue;
	}
	//cout << minValue << endl;
	minright[length - 1] = nums[length - 1];
	minValue = nums[length - 1];
	sum = nums[length - 1];
	for (int i = length - 2; i >= 0; i--)
	{
		if (sum > 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		if (sum < minValue)
		{
			minValue = sum;
		}
		minright[i] = minValue;
	}

	int res = INT_MIN;
	int res1 = INT_MIN;
	int res2 = INT_MIN;
	for (int i = 1; i<nums.size(); i++)
	{
		res1 = max(res1, maxleft[i - 1] - minright[i]);
		res2 = max(res2, maxright[i] - minleft[i - 1]);
		res = max(res1, res2);
	}
	return res;
}
//int main()
//{
//	vector<int>nums = { -5,3,-4,0,0,0,-1,20,1,1,-1,-1,-1,-1,-1 };
//	int res = maxDiffSubArrays(nums);
//	cout << res << endl;
//	system("pause");
//	return 1;
//}

//int main()
//{
//	int c;
//	c = 10^5;
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}
int main() 
{
	int i = -2147483648;
	printf("%d,%d,%d,%d", ~i, -i, 1 - i, -1 - i);
	system("pause");
	return 1;
}