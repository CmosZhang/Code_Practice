#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1217. 总汉明距离
//
//Time Limit Exceeded.第一个版本时间复杂度高。
//第二个版本还是超出时间限制。
//第三个版本还是超出时间限制。
int totalHammingDistance(vector<int> &nums)
{
	// Write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int sum = 0;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			int temp = nums[i] ^ nums[j];
			for (int k = 0; k < 32; k++)   //移位逐步操作
			{
				if ((temp >> k) & 1)
				{
					sum++;
				}
			}
			//while (temp)
			//{
			//	int r = temp % 2;
			//	if (r == 1)
			//	{
			//		sum++;
			//	}
			//	temp >>= 1;
			//}
			//while (temp)
			//{
			//	sum++;
			//	// temp & (temp - 1)每一次可以记一个1
			//	temp = temp & (temp - 1);
			//}
		}
	}
	return sum;
}
/*
优秀的答案。
//我们仔细观察累计汉明距离和0跟1的个数，我们可以发现其实就是0的个数乘以1的个数，
//发现了这个重要的规律，那么整道题就迎刃而解了，只要统计出每一位的1的个数即可，
int totalHammingDistance(vector<int> &nums) 
{
	// Write your code here
	int res=0,n=nums.size();
	for(int i=0;i<32;++i)
	{
		int cnt=0;
		for(int num:nums)
		{
			if(num&(1<<i))
			{
				++cnt;
			}
		}
		res+=cnt*(n-cnt);
	}
	return res;
}
*/

int hammingDistance(int x, int y)
{
	// write your code here
	int sum = 0;
	int temp = x ^ y;
	for (int k = 0; k < 32; k++)   //移位逐步操作
	{
		//if ((((x >> k) & 1)^((y >> k) & 1)) == 1)//这样做也可以
		//{
		//	sum++;
		//}
		if ((temp >> k) & 1)
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	vector<int> num = { 4,14,2 };
	int res = totalHammingDistance(num);
	int x = 1, y = 4;
	int sum = hammingDistance(x, y);
	cout << sum << endl;
	system("pause");
	return 1;
}