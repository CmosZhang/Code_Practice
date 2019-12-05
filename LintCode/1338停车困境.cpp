#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

//1338. 停车困境
//您的提交打败了 40.00% 的提交!
//这道题目的本质实际上取前k间距最小的数
int ParkingDilemma(vector<int> &cars, int k) {
	// write your code here
	if (cars.empty()) {
		return 0;
	}
	sort(cars.begin(), cars.end());
	int res = INT_MAX;
	for (int i = 0; i <= cars.size() - k; i++) {
		int temp = cars[i + k - 1] - cars[i] + 1;
		res = min(res, temp);
	}
	return res;
}