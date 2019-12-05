#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


//20. 骰子求和
//
vector<pair<int, double>> dicesSum(int n)
{
	// Write your code here
	vector<pair<int, double>> results;
	if (n <= 0)
	{
		return results;
	}

	vector<vector<double>> f(n + 1, vector<double>(6 * n + 1, 0));


	//一个色子的情况
	for (int i = 1; i <= 6; ++i)
	{
		f[1][i] = 1.0 / 6;
	}

	//n个色子的情况
	for (int i = 2; i <= n; ++i)// 第 i 个骰子的点数和情况，其情况由前 (i-1) 个 骰子的点数和推出
	{
		for (int j = i; j <= 6 * i; ++j)// i 个骰子的点数和范围，必定为 [i, 6i]，全为1和全为6时，分别取得上下界 
		{
			for (int k = 1; k <= 6; ++k)// 第 n 个骰子的点数只可能为 1到6 
			{
				if (j > k)// j-k 必须严格大于0 (因为在这题中，由于i和j的实际意义分别为，投掷次数，和点数总和，所以两者的最小值都不可能取到0) 
				{
					f[i][j] += f[i - 1][j - k];//相应的，前(n-1)个骰子的点数和，就是 j-k，累加是为枚举所有能凑出 点数和为 j 的情况，并将出现概率求和 
				}
			}
			f[i][j] /= 6.0;// 在没有除以6之前，表示的是在最后一次掷出k点的情况下，n 次投掷得到的点数和为 j 的概率
		}
	}

	/* 解释下 f[i][j] /= 6.0; 
	这句代码;			
	** 我觉得是用到了"条件概率公式"，P(A) = P（A|B）* P(B)
	** 在 f[i][j] 还没有除以6时，它的意思是，在满足第n次掷出k点的情况下，
	n次总共透出点数和为j的概率，即为P（A|B）
	** 而掷出k的概率，由于点数 k 在 1~6之间等可能分布，故为 1/6	
	** 所以除以6以后，它才是真正的 P(A)，
	其实本来该是在  f[i][j] += f[i - 1][j - k]; 句除以6，
	表示 "每种能凑出点数总和为 j 的情况出现的概率之和"，但既然先只是累加求和，
	求完和除以6，也是一样的，毕竟乘法有分配律         
	**             
	*/


	for (int i = n; i <= 6 * n; ++i)
	{
		results.push_back(make_pair(i, f[n][i]));
	}
	return results;
}