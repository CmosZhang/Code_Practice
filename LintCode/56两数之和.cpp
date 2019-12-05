#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

//56. 两数之和
//您的提交打败了 83.40% 的提交!
vector<int> twoSum(vector<int> &numbers, int target)
{
	// write your code here
	if (numbers.empty())
	{
		return numbers;
	}
	int len = numbers.size();
	int low = 0, high = len - 1;
	vector<int> res;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
	return res;
}

//使用排序的方法，并且利用双指针
//您的提交打败了 48.40% 的提交!
//使用pair类型， 第一个元素存放原向量的index， 
//第二个元素存放value， 构造pair类型的vector，
//自己使用比较函数对vector进行排序
struct Less
{
	bool operator()(pair<int, int> &a, pair<int, int> &b)
	{
		return a.second < b.second;
	}
};

vector<int> twoSum2(vector<int> &numbers, int target)
{
	vector<int>res;
	if (numbers.empty())
	{
		return res;
	}
	vector<pair<int, int>> number;
	for (int i = 0; i < numbers.size(); i++) 
	{
		number.push_back(make_pair(i, numbers[i]));
	}
	sort(number.begin(), number.end(),Less());
	int low = 0;
	int high = number.size() - 1;
	while (low < high)
	{
		if (number[low].second + number[high].second == target)
		{
			int t1 = number[low].first;
			int t2 = number[high].first;
			res = { min(t1, t2), max(t1, t2) };
			return res;
		}
		else if (number[low].second + number[high].second > target)
		{
			high--;
		}
		else 
		{
			low++;
		}
	}
	return res;
}



vector<int> twoSum3(vector<int> &numbers, int target) 
{
	if (numbers.empty())
	{
		return numbers;
	}
	vector<int> res;
	unordered_map<int, int> hash;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (hash.find(target - numbers[i]) != hash.end()) 
		{
			// target - nums[i]的下标更小，放在前面
			res.push_back(hash[target - numbers[i]]);
			res.push_back(i);
			return res;
		}
		hash[numbers[i]] = i;
	}
	return res;
}

int main()
{
	vector<int> num = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> res = twoSum2(num, target);
	system("pause");
	return 0;
}