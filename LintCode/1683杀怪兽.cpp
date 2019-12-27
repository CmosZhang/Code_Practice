#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>

using namespace std;


//1683. …±π÷ ﬁ
//

bool canKill(vector<int> &Altman, vector<int> &Monster) {
	for (int i = 0; i < 5; i++) {
		if (Altman[i] < Monster[i]) {
			return false;
		}
	}
	return true;
}

void add(vector<int> &Altman, vector<int> &Monster) {
	for (int i = 0; i < 5; i++) {
		Altman[i] += Monster[i];
	}
}
int killMonster(int n, vector<vector<int>> &v) {
	// 
	if (v.empty() || v[0].empty()) {
		return 0;
	}
	int res = 0;
	list<vector<int>> monster;
	for (int i = 1; i < v.size(); i++) {
		monster.push_back(v[i]);
	}
	bool isKill = true;
	while (isKill) {
		isKill = false;
		auto iter = monster.begin();
		while (iter != monster.end()) {
			if (canKill(v[0], *iter)) {
				add(v[0], *iter);
				monster.erase(iter++);
				isKill = true;
				res++;
			}
			else {
				iter++;
			}
		}
	}
	return res;
}