#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//�� n ����Ʒ��һ����СΪ m �ı���. 
//�������� A ��ʾÿ����Ʒ�Ĵ�С������ V ��ʾÿ����Ʒ�ļ�ֵ.
//�������װ�뱳�����ܼ�ֵ�Ƕ�� ?

//125. �������� II
//�����ύ����� 100.00% ���ύ!
//�����01�������⣬��Դ�����Ͷ�̬�滮
//�趨 f[i][j] ��ʾǰ i ����Ʒװ���СΪ j �ı�����, 
//���Ի�ȡ������ֵ�ܺ�. ���߾��ǵ�i����Ʒװ��װ�뱳��, ����״̬ת�Ʒ��̾��� 
//dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i]]+V[i])
//ʱ��Ϳռ临�ӶȾ�ΪO(n*m),ʱ�临�ӶȻ������Ѿ����ܱ��Ż����ռ临�Ӷȿ��Ա��Ż�ΪO(m).

//���ǿ����������Ž�ı���������Ŀ�У���ʵ�������ֲ�̫��ͬ���ʷ����е���ĿҪ��ǡ��װ��������ʱ�����Ž⣬
//�е���Ŀ��û��Ҫ�����ѱ���װ����һ�������������ʷ���ʵ�ַ������ڳ�ʼ����ʱ��������ͬ��
//����ǵ�һ���ʷ���Ҫ��ǡ��װ����������ô�ڳ�ʼ��ʱ����f[0]Ϊ0����f[1..V]����Ϊ - �ޣ������Ϳ��Ա�֤���յõ���f[N]��һ��ǡ��װ�����������Ž⡣
//�����û��Ҫ�����ѱ���װ��������ֻϣ���۸����󣬳�ʼ��ʱӦ�ý�f[0..V]ȫ����Ϊ0��
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


//�Կռ临�ӶȽ����Ż�
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