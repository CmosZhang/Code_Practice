#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

//5.��K��Ԫ��
//������⣬���28.8%���ύ��
int kthLargestElement(int n, vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0 || n > nums.size())
	{
		return -1;
	}
	sort(nums.begin(), nums.end());
	int len = nums.size();
	return nums[len - n];
}


int main()
{
	vector<int> nums = { 9,3,2,4,8};
	int res = kthLargestElement(3,nums);
	cout << res << endl;
	system("pause");
	return 1;
}