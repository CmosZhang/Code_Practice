#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//144. 交错正负数
//您的提交打败了 48.80% 的提交!
void rerange(vector<int> &A) 
{
	// write your code here
	if (A.empty() || A.size() == 0)
	{
		return;
	}

	int len = A.size();

	int negNum = 0;
	int posNum = 0;
	for (int i = 0; i < len; i++)
	{
		if (A[i] < 0)
		{
			negNum++;
		}
		else
		{
			posNum++;
		}
	}

	//判断是正数还是负数放在数组的第一个位置
	int posIndex = 1;
	int negIndex = 0;

	if (posNum > negNum) 
	{
		posIndex = 0;
		negIndex = 1;
	}

	while (posIndex < len&&negIndex < len)
	{
		while (A[posIndex] > 0 && posIndex < len)
		{
			posIndex += 2;
		}
		while (A[negIndex] < 0 && negIndex < len)
		{
			negIndex += 2;
		}
		if (posIndex < A.size() && negIndex < A.size())
		{
			int temp = A[posIndex];
			A[posIndex] = A[negIndex];
			A[negIndex] = temp;
			posIndex += 2;
			negIndex += 2;
		}
	}
}

int main()
{
	vector<int> nums = { -2,3,5,6,-2,-3 };
	rerange(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}