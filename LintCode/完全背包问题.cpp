#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//��ȫ���������������б�ŷֱ�Ϊa,b,c,d���ļ���Ʒ�����ǵ������ֱ���2,3,4,7��
//���ǵļ�ֵ�ֱ���1,3,5,9��ÿ����Ʒ�������޸������ڸ��������Ϊ10�ı�����
//����ñ�����װ�����Ʒ�������ļ�ֵ�ܺͣ�

//��ȫ����������01�����������������ÿһ����Ʒ�������������޸�����01����ÿ����Ʒ����ֻ��һ����

//˼·��
//dp[i][j]��ʾǰi����Ʒ���뵽һ������Ϊj�ı����л�õ����ֵ����ô���ڵ�i����Ʒ
//������k��ѡ��0<=k*v[i]<=j,������ѡ��0��1��2��k����i����Ʒ
//״̬ת�Ʒ���Ϊ��dp[i][j] = max(dp[i-1][j-v[i]*k]+p[i]*k);0<=k*v[i]<=t
//dp[0][j]=0,dp[i][0]=0;

int Knapsack(int n, vector<int>&weight, vector<int>&value) {
	vector<vector<int>>dp(weight.size(), vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[0][i] = (i / weight[0])*value[0];
	}
	for (int i = 1; i < weight.size(); i++) {
		for (int j = 0; j <= n; j++) {
			if (j < weight[i]) {//��Ʒi���ܷ��뱳��
				dp[i][j] = dp[i - 1][j];
			}
			else {
				for (int k = 0; k*weight[i] <= j; k++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i] * k] + k * value[i]);
				}
				//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	return dp[weight.size() - 1][n];
}


//��������
//�ռ��ϵļ򻯣�
//i =0 ʱ��ֻ�ŵ�һ����Ʒ���ܻ�õ�����ֵ
//i=1ʱ�����ϵڶ�����Ʒ���ܻ�õ�����ֵ
int Knapsack2(int n, vector<int>&weight, vector<int>&value) {
	vector<int>dp(n + 1, 0);
	for (int i = 0; i < weight.size(); i++) {
		for (int j = weight[i]; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp[n];
}

int main() {
	int n = 10;
	vector<int> weight = { 2,3,4,7 };
	vector<int> value = { 1,3,5,9 };
	cout << Knapsack2(n, weight, value) << endl;
	system("pause");
	return 0;
}