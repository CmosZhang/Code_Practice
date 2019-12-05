#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

//607. 两数之和 III-数据结构设计
//您的提交打败了 57.00% 的提交!

class TwoSum {
public:
	/**
	 * @param number: An integer
	 * @return: nothing
	 */
	void add(int number) {
		// write your code here
		num.push_back(number);
	}

	/**
	 * @param value: An integer
	 * @return: Find if there exists any pair of numbers which sum is equal to the value.
	 */
	bool find(int value) {
		// write your code here
		unordered_map<int, int> mp;
		for (auto i:num) {
			if (mp.find(value - i) != mp.end()) {
				return true;
			}
			mp[i] = i;
		}
		return false;
	}
private:
	vector<int> num;
};