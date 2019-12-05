#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//749. 约翰的后花园
//您的提交打败了 72.83% 的提交!
string isBuild(int x)
{
	// write you code here
	vector<bool> dp(x + 1, false);
	dp[0] = true;
	if (x >= 3)
	{
		dp[3] = true;
		for (int i = 7; i <= x; i++)
		{
			if (dp[i - 7] || dp[i - 3])
			{
				dp[i] = true;
			}
		}
	}
	return dp[x] == true ? "YES" : "NO";
}

int main()
{
	int x = 56;
	string ans = isBuild(x);
	cout << ans << endl;
	system("pause");
	return 0;
}