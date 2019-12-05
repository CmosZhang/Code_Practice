#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//382. 三角形计数
//直接遍历求解，算法复杂度较高，O(n^3)
//您的提交打败了 9.40% 的提交!
//int triangleCount(vector<int> &S)
//{
//	// write your code here
//	if (S.empty() || S.size() <= 2)
//	{
//		return 0;
//	}
//	int res = 0;
//	sort(S.begin(), S.end());
//	int len = S.size();
//	for (int i = 0; i < len - 2; i++)
//	{
//		for (int j = i + 1; j < len - 1; j++)
//		{
//			for (int k = j + 1; k < len; k++)
//			{
//				if (S[i] + S[j] > S[k])
//				{
//					res++;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//	}
//	return res;
//}


//您的提交打败了 100.00% 的提交!
int triangleCount(vector<int> &S)
{
	if (S.empty() || S.size() <= 2)
	{
		return 0;
	}
	int res = 0;
	sort(S.begin(), S.end());

	for (int i = 1; i < S.size(); i++)
	{
		int left = 0, right = i - 1;
		while (left < right)
		{
			if (S[left] + S[right] > S[i])
			{
				res += right - left;
				right--;
			}
			else
			{
				left++;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 3, 4, 6, 7 };
	cout << triangleCount(nums) << endl;
	system("pause");
	return 0;
}