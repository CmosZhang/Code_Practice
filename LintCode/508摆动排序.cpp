#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;


//508. 摆动排序
//您的提交打败了 83.00% 的提交!
void wiggleSort(vector<int> &nums) 
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return;
	}
	int len = nums.size();
	//方法一
	//vector<int> num1 = nums;
	//vector<int> num2 = nums;

	//sort(num1.begin(), num1.end());//升序排列
	//sort(num2.begin(), num2.end(), greater<int>());//降序排列

	//int j = 0;
	//for (int i = 0; i < len - 1; i = i + 2)
	//{
	//	nums[i] = num1[j];
	//	nums[i + 1] = num2[j];
	//	j++;
	//}
	//if (len % 2 == 1)
	//{
	//	nums[len - 1] = num1[j];
	//}
	//方法二，先降序排序，然后两两交换位置
	sort(nums.begin(),nums.end(),greater<int>());
	for (int i = 0; i < len - 1; i = i + 2)
	{
		int temp = nums[i];
		nums[i] = nums[i + 1];
		nums[i + 1] = temp;
	}
}

int main()
{
	vector<int> nums = { 2,1,3,4,5,6 };
	wiggleSort(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}