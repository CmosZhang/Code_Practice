#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//����һЩ��Ʒ�����һ��Ŀ��ֵ�����ж����ֿ������Ŀ����������
//���������Ʒ���� [2,3,6,7] ��Ŀ��ֵ 7, ��ô����2�ֿ��ܣ�[7] �� [2, 2, 3]�����Է���2��
//�����Ҳ����������������1��2��5��10Ӳ��������������ʴ�80Ԫ�ķ���������

//Ӳ�ҿ����ظ�ѡ��
//״̬ת�Ʒ��̣�
//dp[i][j]����ǰi��Ӳ�Ҵճ�jԪ�ķ�������  
//dp[i][j]=dp[i-1][j]+dp[i-1][j-A[i]*1]+dp[i-1][j-A[i]*2]+...+

int backpack(vector<int>&item, int target) {
	int len = item.size();
	vector<vector<int>> dp(len + 1, vector<int>(target, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j <= target; j++) {
			int k = 0;
			while (k*item[i - 1] < j) {
				dp[i][j] += dp[i - 1][j - item[i - 1] * k];
				k++;
			}
		}
	}
	return dp[len][target];
}

//���Ӳ�Ҳ����ظ�ѡ��ÿ��Ӳ��ֻ��ʹ��һ��
//dp[i][j]��ʾǰi��Ӳ�Ҵճ�jԪ�ķ���
//dp[i][j] = dp[i-1][j]+dp[i-1][j-A[i]]
//dp[0][0] = 1
int backpack2(vector<int>&item, int target) {
	int len = item.size();
	vector<vector<int>> dp(len + 1, vector<int>(target, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			if (item[i - 1] <= j) {
				dp[i][j] += dp[i - 1][j - item[i - 1]];
			}
		}
	}
	return dp[len][target];
}