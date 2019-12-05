#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//83落单的数II；
int singleNumberII(vector<int> &A) 
{
	// write your code here
	//sort(A.begin(), A.end());
	int length = A.size();
	int ones = 0;       
	int twos = 0;
	for (int i = 0; i < length; i++)
	{
	    ones = (ones ^ A[i]) & (~twos);           
		twos = (twos ^ A[i]) & (~ones); 
	}         
	return ones;
}

//84. 落单的数 III
//这种方法时间复杂度比较高，打败了72%的提交，运行时间3220ms。
//还可以再优化。
vector<int> singleNumberIII(vector<int> &A)
{
	// write your code here
	vector<int> res;
	if (A.size() <= 0)
	{
		return res;
	}
	sort(A.begin(), A.end());
	if (A[0] != A[1])
	{
		res.push_back(A[0]);
	}
	int len = A.size();
	for (int i = 1; i <= len - 2; i++)
	{
		if (A[i] != A[i - 1] && A[i] != A[i + 1])
		{
			res.push_back(A[i]);
		}
	}
	if (A[len - 2] != A[len - 1])
	{
		res.push_back(A[len-1]);
	}
	return res;
}
/* 方法二：利用set的特性来做
vector<int> singleNumberIII(vector<int> &A)
{
	// write your code here
	vector<int> res;
	if (A.size() <= 0)
	{
		return res;
	}
	int len = A.size();
	set<int> data;
	set<int>::iterator it;
	for (int i = 0; i<len; i++)
	{
		if (data.find(A[i]) == data.end())
		{
			data.insert(A[i]);
		}
		else
		{
			it = data.find(A[i]);
			data.erase(it);
		}
	}
	it = data.begin();
	res.push_back(*it);
	res.push_back(*(++it));
	return res;
}*/

//方法三
//严格控制算法的时间复杂度和空间复杂度
//时间复杂度为O(n),空间复杂度为O(1)
//您的提交打败了 59.80% 的提交!
vector<int> singleNumberIII(vector<int> &A) {
	// write your code here
	vector<int> res(2);
	if (A.empty())
	{
		return res;
	}
	int len = A.size();
	int x = 0;
	//x代表两个只出现一次的数的异或结果
	for (int i = 0; i < len; i++)
	{
		x ^= A[i];
	}
	//找到x的二进制表示式中，第一个为1的位置，从低位到高位。
	int pos;
	for (int i = 0; i < 32; ++i)
	{
		if (x & (1 << i)) 
		{
			pos = i;
			break;
		}
	}
	//以1的位置为界限，划分为两个子数组，两个不同的数就分别在这两个数组当中
	//依次异或就求出这两个数
	for (int i = 0; i < len; ++i)
	{
		if (A[i] & (1 << pos))
			res[0] ^= A[i];
		else
			res[1] ^= A[i];
	}
	return res;
}


//824. 落单的数 IV
//给定数组，除了一个数出现一次外，所有数都出现两次，
//并且所有出现两次的数都挨着。请找出找出那个出现一次的数。
//暴力求解，您的提交打败了 99.66% 的提交!
//用二分法最好
int getSingleNumber(vector<int> &nums) 
{
	// Write your code here
	//sort(nums.begin(), nums.end());
	if (nums[0] != nums[1])
	{
		return nums[0];
	}
	int len = nums.size();
	for (int i = 2; i < len - 1; i++)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
		{
			return nums[i];
		}
	}
	if (nums[len - 2] != nums[len - 1])
	{
		return nums[len-1];
	}
}


int main()
{
	//vector<int>nums = { 1,2,3,3,2,4,1,5 };
	//vector<int>res;
	//res = singleNumberIII(nums);
	//for (int i = 0; i < res.size(); i++)
	//{
	//	cout << res[i] << ' ';
	//}
	//cout << endl;

	vector<int>nums = { 3,3,2,2,4,5,5 };
	int res2;
	res2 = getSingleNumber(nums);
	cout << res2 << endl;


	system("pause");
	return 1;
}