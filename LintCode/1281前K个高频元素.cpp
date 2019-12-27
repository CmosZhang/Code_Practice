#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

//1281. 前K个高频元素
//
vector<int> topKFrequent(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty() || k >= nums.size()) {
		return nums;
	}
	vector<int> res;

}