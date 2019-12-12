#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//1303. H指数 II 
//这道题目中，citations是排过序的
//最简单的方法是利用后缀和的方式，详细解答过程在1304 H指数这道题目中有解答。
int hIndex(vector<int> &citations) {
	// write your code here
	if (citations.empty()) {
		return 0;
	}
	int res = 0;
	int maxCit = citations[citations.size() - 1];
	for (int i = maxCit; i >= 0; i--) {
		int count = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) {
				count++;
			}
		}
		if (count >= i) {
			res = max(i, res);
			break;
		}
	}
	return res;
}

int main() {
	vector<int> cit = { 0,1,3,5,6 };
	cout << hIndex(cit) << endl;
	system("pause");
	return 0;
}