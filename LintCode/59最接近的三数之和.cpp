#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//59. 最接近的三数之和
//通过分析，我们可以想到一种时间复杂度为O(n^2)的解法：
//假设数组中有len个元素，首先我们将数组中的元素按照从小到大的顺序进行排序
//其次，看最终取出的三个数中的第一个数，若数组长度为n，那么有n种取法。
//假设取的第一个数是A[i]，那么第二三两个数从A[i+1]~A[len]中取出。
//找到“第一个数为A[i]固定，后两个数在A[i]后面元素中取。并且三数之和离target最近的情况。”
//这时，我们用两个指针j,k分别指向A[i+1]和A[len]，
//如果此时三数之和A[i]+A[j]+A[k]<target，说明三数之和小了，
//我们将j后移一格；反之，若和大于target，则将k前移一格；
//直到j和k相遇为止。在这期间，保留与target最近的三数之和。
//一旦发现有“和等于target的情况”,立即输出即可。
//您的提交打败了 84.00% 的提交!
int threeSumClosest(vector<int> &numbers, int target)
{
	// write your code here
	int res = numbers[0] + numbers[1] + numbers[2];
	int dis = abs(res - target);//计算三数之和与目标值的差
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++)
	{
		int j = i + 1, k = numbers.size() - 1;
		while (j < k)
		{
			int sum = numbers[i] + numbers[j] + numbers[k];
			int temp = abs(sum - target);
			if (temp < dis)//找到与目标值最小差值的三数之和
			{
				dis = temp;
				res = sum;
			}
			if (sum < target)
			{
				j++;
			}
			else if (sum > target)
			{
				k--;
			}
			else
			{
				return res;
			}
		}
	}
	return res;
}

//最接近的三数之和，第二种方法
//您的提交打败了 65.20% 的提交!
int threeSumClosest(vector<int> &numbers, int target)
{
	if (numbers.empty() || numbers.size() < 3)
	{
		return -1;
	}
	sort(numbers.begin(), numbers.end());
	int res = numbers[0] + numbers[1] + numbers[2];
	for (int i = 0; i < numbers.size(); i++)
	{
		int left = i + 1, right = numbers.size() - 1;
		while (left < right)
		{
			if (abs(res - target) > abs(numbers[i] + numbers[left] + numbers[right] - target))
			{
				res = numbers[i] + numbers[left] + numbers[right];
			}
			if (numbers[i] + numbers[left] + numbers[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return res;
}

//57. 三数之和
//您的提交打败了 24.20% 的提交!
//使用python的话打败50%的提交
vector<vector<int>> threeSum(vector<int> &numbers) 
{
	// write your code here
	vector<vector<int>>res;
	if (numbers.size() <= 0)
	{
		return res;
	}
	sort(numbers.begin(), numbers.end());
	int len = numbers.size();
	for (int i = 0; i < len - 2; i++)
	{
		if (i == 0 || numbers[i] > numbers[i - 1])
		{
			int left = i + 1;
			int right = len - 1;
			while (left < right)
			{
				int sum = numbers[left] + numbers[right] + numbers[i];
				if (sum == 0)
				{
					vector<int> temp = { numbers[i], numbers[left], numbers[right] };
					res.push_back(temp);
					left++;
					right--;//底下的这两个while循环主要是为了去除重复元素
					while (left < right&&numbers[left] == numbers[left - 1])
					{
						left++;
					}
					while (left < right&&numbers[right] == numbers[right + 1])
					{
						right--;
					}
				}
				else if (sum < 0)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<int>num = { -1, 2, 1, -4 };
	int target = 1;
	int res = threeSumClosest(num, target);
	cout << res << endl;
	system("pause");
	return 1;
}