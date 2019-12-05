#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//使用set，利用辅助空间的思想来做。
vector<vector<int>> fourSum(vector<int> &numbers, int target)
{
	//vector<vector<int>> res;
	set<vector<int>> res;
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < int(numbers.size() - 3); ++i) {
		for (int j = i + 1; j < int(numbers.size() - 2); ++j) {
			if (j > i + 1 && numbers[j] == numbers[j - 1]) continue;
			int left = j + 1, right = numbers.size() - 1;
			while (left < right) {
				int sum = numbers[i] + numbers[j] + numbers[left] + numbers[right];
				if (sum == target) {
					vector<int> out{ numbers[i], numbers[j], numbers[left], numbers[right] };
					res.insert(out);
					++left; --right;
				}
				else if (sum < target) ++left;
				else --right;
			}
		}
	}
	return vector<vector<int>>(res.begin(), res.end());
}


//方法二，不需要使用set。
vector<vector<int>> fourSum(vector<int> &numbers, int target)
{
	vector<vector<int>> res;
	if (numbers.empty() || numbers.size() < 4)
	{
		return res;
	}
	int len = numbers.size();
	sort(numbers.begin(), numbers.end());
	vector<int> temp;
	for (int i = 0; i < len - 3; i++)
	{
		if (i && numbers[i] == numbers[i - 1]) 
			continue;
		for (int j = i + 1; j < len - 2; j++)
		{
			if (j > i + 1 && numbers[j] == numbers[j - 1]) 
				continue;
			int left = j + 1;
			int right = len - 1;
			int sum = target - numbers[i] - numbers[j];
			while (left < right)
			{
				if (numbers[left] + numbers[right] == sum)
				{
					temp.clear();
					temp.push_back(numbers[i]);
					temp.push_back(numbers[j]);
					temp.push_back(numbers[left]);
					temp.push_back(numbers[right]);
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
				else if (numbers[left] + numbers[right] > sum)
				{
					right--;			
				}
				else
				{
					left++;
				}
			}
		}
	}
	return res;
}


int main()
{
	vector<int> p;
	int a;
	for (int i = 0; i < 6; i++)
	{
		cin >> a;
		p.push_back(a);
	}

	int target = 0;
	vector<vector<int>> b;
	b = fourSum(p, 0);



	system("pause");
	return 1;

}