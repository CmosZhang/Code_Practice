#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//有 n 个物品和一个大小为 m 的背包. 
//给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
//问最多能装入背包的总价值是多大 ?

//125. 背包问题 II
//您的提交打败了 100.00% 的提交!
//经典的01背包问题，资源分配型动态规划
//设定 f[i][j] 表示前 i 个物品装入大小为 j 的背包里, 
//可以获取的最大价值总和. 决策就是第i个物品装不装入背包, 所以状态转移方程就是 
//dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i]]+V[i])
//时间和空间复杂度均为O(n*m),时间复杂度基本上已经不能被优化，空间复杂度可以被优化为O(m).

//我们看到的求最优解的背包问题题目中，事实上有两种不太相同的问法。有的题目要求“恰好装满背包”时的最优解，
//有的题目则并没有要求必须把背包装满。一种区别这两种问法的实现方法是在初始化的时候有所不同。
//如果是第一种问法，要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为 - ∞，这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解。
//如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。
int backPackII(int m, vector<int> &A, vector<int> &V) {
	// write your code here
	vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= A.size(); i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (A[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + V[i - 1]);
			}
		}
	}
	return dp[A.size()][m];
}


//对空间复杂度进行优化
int backPackII(int m, vector<int> A, vector<int> V) {
	// write your code here
	vector<int> f(m + 1, 0);
	int n = A.size();
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= A[i]; j--) {
			f[j] = max(f[j], f[j - A[i]] + V[i]);
		}
	}
	return f[m];
}