#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//159. Ѱ����ת���������е���Сֵ
//���ֲ��ҵ�˼�룬���鵱��û���ظ���Ԫ�ء�
int findMin(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return -1;
	}
	int l = nums.size();
	int low = 0, high = l - 1, mid;
	if (nums.size() == 1)
	{
		return nums[0];
	}
	//�������б�����������
	if (nums[low] < nums[high])
	{
		return nums[low];
	}
	//�������б������ǽ���
	if (nums[high] < nums[high - 1])
	{
		return nums[high];
	}
	//����˳�򱻴��ң���Ϊ��ת����
	while (low < high)
	{
		mid = (low + high) / 2;
		if (nums[mid] > nums[high])
			low = mid + 1;
		else
			high = mid;
	}
	return nums[low];
}


//160. Ѱ����ת���������е���Сֵ II
//ֱ�ӱ�����⣬���97%���ύ��û���κμ��ɡ�
 int findMinII(vector<int> &nums)
 {
        // write your code here
    if(nums.size()<=0)
    {
        return -1;
    }
    if (nums.size() == 1)
	{
		return nums[0];
	}
	int l = nums.size();
	int low = 0, high = l - 1, mid;
	//�������б�����������
	if (nums[low] < nums[high])
	{
		return nums[low];
	}
	int min = nums[0];
	for(int i=0;i<l;i++)
	{
	    if(min>nums[i])
	    {
	        min = nums[i];
	    }
	}
	return min;
}



int main()
{
	vector<int> nums = { 4,5,6,6,7,0,1,2,2,2};
	int res = findMinII(nums);
	cout << res << endl;
	system("pause");
	return 1;
}