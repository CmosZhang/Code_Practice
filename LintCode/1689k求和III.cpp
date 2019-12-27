#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//1689. k«Û∫ÕIII
//
int count1;

void helper(vector<int> &A, vector<int> &sol, int k, int index, int target, bool isOdd) {
	if (sol.size() == k && target == 0) {
		count1++;
		return;
	}
	if (target < 0) {
		return;
	}
	for (int i = index; i < A.size(); i++) {
		if (isOdd && !(A[i] & 0x1)) {
			continue;
		}
		else if (!isOdd &&A[i] & 0x1) {
			continue;
		}
		if (A[i] > target) {
			return;
		}
		sol.push_back(A[i]);
		helper(A, sol, k, i + 1, target - A[i], isOdd);
		sol.pop_back();
	}
}

int getAns(vector<int> &a, int k, int target) {
	if (a.empty()) {
		return -1;
	}
	count1 = 0;
	sort(a.begin(), a.end());
	vector<int> sol;
	helper(a, sol, k, 0, target, true);
	sol.clear();
	helper(a, sol, k, 0, target, false);
	return count1;
}