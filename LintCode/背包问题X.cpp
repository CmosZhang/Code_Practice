#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//���ܹ���nԪ�������ܹ���������Ʒ�����ǵļ۸�ֱ���150Ԫ,250Ԫ,350Ԫ��
//������Ʒ������������Ϊ�����޶�ģ���������Ʒ�Ժ���Ҫ��ʣ�µ�Ǯ��������ΪС�ѣ�
//��������Ҫ�����˶���С��

//˼·����ȫ�������⣬ÿ����Ʒ����ȡ���޶�

int backPackX(int n) {
	// write your code here
	vector<int>dp(n + 1, 0);
	int prices[3] = { 150,250,350 };
	for (int i = 0; i < 3; i++) {
		for (int j = prices[i]; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - prices[i]] + prices[i]);
		}
	}
	int res = n - dp[n];
	return res;
}