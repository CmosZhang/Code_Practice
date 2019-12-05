#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//1478. 最接近target的值
//
int closestTargetValue(int target, vector<int> &array) {
	// Write your code here
	if (array.empty()) {
		return 0;
	}
	sort(array.begin(), array.end());
	int diff = 1e9 + 50;
	int left = 0;
	int right = array.size() - 1;
	while (left < right) {
		if (array[left] + array[right] > target) {
			right--;
		}
		else {
			diff = min(diff, target - (array[left] + array[right]));
			left++;
		}
	}
	if (diff == 1e9 + 50) {
		return -1;
	}
	else {
		return target - diff;
	}
}
