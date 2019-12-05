#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//548. 两数组的交集 II
//您的提交打败了 79.20% 的提交!
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
	// write your code here
	vector<int> res;
	if (nums1.empty() || nums2.empty())
	{
		return res;
	}

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
	while (it1 != nums1.end() && it2 != nums2.end())
	{
		if (*it1 < *it2)
		{
			it1++;
		}
		else if (*it1 > *it2)
		{
			it2++;
		}
		else
		{
			res.push_back(*it1);
			it1++;
			it2++;
		}
	}
	return res;
}


int main()
{
	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	vector<int> res = intersection(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}