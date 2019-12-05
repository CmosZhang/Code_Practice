#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int surfaceArea(vector<vector<int>> &local) {
	int ans = 0;
	for (int i = 0; i < local.size(); i++) {
		int sum = 0;
		for (int j = 0; j < local[0].size(); j++) {
			ans += abs(local[i][j] - sum);
			sum = local[i][j];
		}
		ans += sum;
	}
	for (int j = 0; j < local[0].size(); j++) {
		int sum = 0;
		for (int i = 0; i < local.size(); i++) {
			ans += abs(local[i][j] - sum);
			sum = local[i][j];
		}
		ans += sum;
	}
	//¸©ÊÓÍ¼
	int temp = 0;
	for (int i = 0; i < local.size(); i++) {
		for (int j = 0; j < local[0].size(); j++)
			if (local[i][j] != 0)
				temp++;
	}
	ans += temp * 2;
	return ans;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> local(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> local[i][j];
		}
	}
	cout << surfaceArea(local) << endl;
	system("pause");
	return 0;
}