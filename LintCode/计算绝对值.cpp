#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<long long>num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	if (num.size() == 2) {
		cout << num[0] << " " << num[1] << endl;
	}
	else {
		map<long long, pair<long long, long long>> mp;
		for (int i = num.size() - 1; i >= 1; i--) {
			long long dif = abs(num[i] - num[i - 1]);
			pair<long long, long long> tmp = { num[i - 1],num[i] };
			mp[dif] = tmp;
		}
		long long  res1 = mp.begin()->second.first;
		long long  res2 = mp.begin()->second.second;
		cout << res1 << " " << res2 << endl;
	}
}