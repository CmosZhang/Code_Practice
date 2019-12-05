#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//507. �ڶ����� II
//�����ύ����� 56.60% ���ύ!
void wiggleSort(vector<int> &nums)
{
	// write your code here
	if (nums.empty() || nums.size() < 2)
	{
		return;
	}
	int len = nums.size();
	vector<int> arr = nums;
	sort(arr.begin(), arr.end());
	int left = (len - 1) / 2;
	int right = len - 1;
	int index = 0;
	while (left >= 0 && right >= (len + 1) / 2) 
	{
		nums[index++] = arr[left--];
		nums[index++] = arr[right--];
	}
	//��nums���м��ֵ
	if (left >= 0) 
	{
		nums[index] = arr[left];
	}
}

int main()
{
	vector<int> nums = { 1, 5, 1, 1, 6, 4 };
	wiggleSort(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}