#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;


//508. �ڶ�����
//�����ύ����� 83.00% ���ύ!
void wiggleSort(vector<int> &nums) 
{
	// write your code here
	if (nums.empty() || nums.size() <= 1)
	{
		return;
	}
	int len = nums.size();
	//����һ
	//vector<int> num1 = nums;
	//vector<int> num2 = nums;

	//sort(num1.begin(), num1.end());//��������
	//sort(num2.begin(), num2.end(), greater<int>());//��������

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
	//���������Ƚ�������Ȼ����������λ��
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