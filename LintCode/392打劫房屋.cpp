#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// 392打劫房屋
//使用动态规划来解题
long long houseRobber(vector<int> &A)
{
	// write your code here
	int l = A.size();
	if (l <= 0)
	{
		return 0;
	}
	if (l == 1)
	{
		return A[0];
	}
	vector<long long>dp(l, 0);
	dp[0] = A[0];
	dp[1] = max(A[0],A[1]);
	for (int i = 2; i < l; i++) 
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
	}
	return dp[l - 1];
}


//534打劫房屋 II
//使用动态规划解题。
int houseRobber2(vector<int> &nums) 
{
	// write your code here
		int l = nums.size();
		if (l <= 0)
		{
			return 0;
		}
		if (l == 1)
		{
			return nums[0];
		}
		//最后一间房子不打劫，从第一间房子开始打劫。
		vector<int>dp_1(l - 1, 0);
		dp_1[0] = nums[0];
		dp_1[1] = max(nums[1], nums[0]);
		for (int i = 2; i < l - 1; i++)
		{
			dp_1[i] = max(dp_1[i - 2] + nums[i], dp_1[i - 1]);
		}
		//最后一间房子打劫，第一件房子不打劫，从第二间房子开始打劫。
		vector<int>dp_2(l - 1, 0);
		dp_2[0] = nums[1];
		dp_2[1] = max(nums[1], nums[2]);
		for (int i = 3; i < l; i++)
		{
			dp_2[i-1] = max(dp_2[i - 3] + nums[i], dp_2[i - 2]);
		}
		cout << dp_1[l - 2] << dp_2[l - 2] << endl;
		return max(dp_1[l - 2], dp_2[l - 2]);
}




int main()
{
	vector<int>num ={828,125,740,724,983,321,773,678,841,842,875,377,674,144,340,467,625,916,463,922,255,662,692,123,778,766,254,559,480,483,904,60,305,966,872,935,626,691,832,998,508,657,215,162,858,179,869,674,452,158,520,138,847,452,764,995,600,568,92,496,533,404,186,345,304,420,181,73,547,281,374,376,454,438,553,929,140,298,451,674,91,531,685,862,446,262,477,573,627,624,814,103,294,388};
	//int temp;
	//for (int i = 0; i < 3; i++)
	//{
	//	cin >> temp;
	//	num.push_back(temp);
	//}
	int res;
	res = houseRobber2(num);
	cout << res << endl;
	system("pause");
	return 1;
}