#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

vector<int> GetResult(int n, int m, map<int, int> mp, vector<int>&num2) {
	vector<int> res;
	int ma = m - 1;
	bool again = false;
	while (ma != -1) {
		again = false;
		for (int i = 0; i < num2.size(); ) {
			int k = num2[i];
			int re = ma - k;
			if (mp.find(re) != mp.end()) {
				again = true;
				mp[re]--;
				if (mp[re] == 0) {
					mp.erase(re);
				}
				num2.erase(num2.begin() + i);
				res.push_back(ma);
			}
			else if (mp.find(m + re) != mp.end()) {
				mp[m + re]--;
				if (mp[m + re] == 0) {
					mp.erase(m + re);
				}
				num2.erase(num2.begin() + i);
				res.push_back(ma);
			}
			else {
				i++;
				again = false;
			}
		}
		if (!again) {
			ma--;
		}
	}
	return res;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> num1(n);
	vector<int> num2(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> num1[i];
		mp[num1[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> num2[i];
	}
	vector<int> res = GetResult(n, m, mp, num2);
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " ";
	}
	cout << res[n - 1] << endl;
	return 0;
}