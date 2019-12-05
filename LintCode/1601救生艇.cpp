#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<map>

using namespace std;


//1601. 救生艇
//您的提交打败了 100.00% 的提交!
int numRescueBoats(vector<int> &people, int limit) {
	// Write your code here.
	if (people.empty()) {
		return 0;
	}
	sort(people.begin(), people.end());
	if (people[0] >= limit) {
		return people.size();
	}
	int len = people.size();
	int low = 0;
	int high = len - 1;
	int res = 0;
	while (low < high) {
		if (people[low] + people[high] <= limit) {
			res++;
			low++;
			high--;
		}
		else {
			res++;
			high--;
		}
	}
	if (low == high) {
		res++;
	}
	return res;
}

int main() {
	vector<int> num = { 3,5,3,4 };
	int limit = 5;
	cout << numRescueBoats(num, limit) << endl;
	system("pause");
	return 1;
}