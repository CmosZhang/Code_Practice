#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//������������ n Ԫ���������ж��ִ��׿���ѡ��ÿ�ִ��׶��Ǵ�װ�ģ�
//�����������򣬸���ÿ�ִ��׵��������۸��Լ������������������ٹ���Ĵ���

//��ʵ���������Կ�����һ�����ر�������,��01�����Ļ����϶���һ��ѭ��


//˼·������Ʒ�Ĳ�ͬ�����Ĵ�������ǲ�ͬ����Ʒ
//Ȼ��ʹ��0-1�����ķ������
//f[i]Ϊ������iԪʱ�������Ĵ�������
//״̬ת�Ʒ���Ϊ��f[i] = max(f[i],f[k-prices[i]]+weight[i]);
int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
	int m = prices.size();
	vector<int> f(n + 1, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= amounts[i]; j++) {
			for (int k = n; k >= prices[i]; k--) {
				f[k] = max(f[k], f[k - prices[i]] + weight[i]);
			}
		}
	}
	return f[n];
}

int main() {
	int V, m;
	while (cin >> V >> m) {
		vector<int> amount(m);
		vector<int> weight(m);
		vector<int> prices(m);
		for (int i = 0; i < m; i++) {
			cin >> amount[i] >> weight[i] >> prices[i];
		}
		cout << backPackVII(V, weight,prices , amount) << endl;
	}
}