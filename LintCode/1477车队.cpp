#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<map>

using namespace std;


//1477. 车队
//网上的优秀答案
//您的提交打败了 83.78% 的提交!
//int carFleet(int target, vector<int> &position, vector<int> &speed) {
//	// Write your code here
//	if (position.empty() || speed.empty()) {
//		return 0;
//	}
//	map<int, double> mp;
//	for (int i = 0; i < position.size(); i++) {
//		mp[-position[i]] = (double)(target - position[i]) / speed[i];
//	}
//	int res = 0;
//	double cur = 0;
//	for (auto it : mp) {
//		cout << it.second << endl;
//		if (it.second > cur) {
//			cur = it.second;
//			res++;
//		}
//	}
//	return res;
//}


//自己的做法
//您的提交打败了 83.78% 的提交!
static bool compare(pair<int, double>&a, pair<int, double>&b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}
	return a.second < b.second;
}

int carFleet(int target, vector<int> &position, vector<int> &speed) {
	// Write your code here
	if (position.empty() || speed.empty()) {
		return 0;
	}
	vector<pair<int, double>> car;
	for (int i = 0; i < position.size(); i++) {
		pair<int, double> temp;
		temp.first = position[i];
		temp.second = (double)(target - position[i]) / speed[i];
		car.push_back(temp);
	}
	//将车按照位置降序排列
	sort(car.begin(), car.end(), compare);
	int res = 0;
	double cur = 0;
	for (int i = 0; i < car.size(); i++) {
		if (car[i].second > cur) {
			cur = car[i].second;
			res++;
		}
	}
	return res;
}

int main() {
	int target;
	cin >> target;
	vector<int> pos = { 10,8,0,5,3 };
	vector<int> speed = { 2,4,1,1,3 };
	cout << carFleet(target, pos, speed) << endl;
	system("pause");
	return 1;
}