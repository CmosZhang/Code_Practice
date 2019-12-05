#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

//1206. 下一个更大的数 I
//您的提交打败了 13.07% 的提交!
//直接暴力求解，算法的时间复杂度比较高
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
	// Write your code here
	vector<int> res;
	if (nums1.empty() || nums2.empty()) {
		return res;
	}
	//sort(nums2.begin(), nums2.end());
	for (int i = 0; i < nums1.size(); i++) {
		bool flag = false;
		for (int j = 0; j < nums2.size(); j++) {
			if (nums2[j] != nums1[i]) {
				continue;
			}
			else {
				if (j == nums2.size() - 1) {
					res.push_back(-1);
				}
				else {
					while (j < nums2.size()) {
						if (nums2[j] > nums1[i]) {
							flag = true;
							res.push_back(nums2[j]);
							break;
						}
						j++;
					}
					if (!flag) {
						res.push_back(-1);
					}
				}
			}
		}
	}
	return res;
}

//网上优秀的答案
//直接利用哈希映射
//您的提交打败了 100.00% 的提交!
//但这道题目的算法时间复杂度和空间复杂度并没有很低
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
	// Write your code here
	vector<int> res;
	if (nums1.empty() || nums2.empty()) {
		return res;
	}
	for (int i = 0; i < nums1.size(); i++) {
		res.push_back(-1);
	}
	unordered_map<int, int> mp;
	for (int i = 0; i < nums2.size(); i++) {
		mp[nums2[i]] = i;
	}
	for (int i = 0; i < nums1.size(); i++) {
		auto iter = mp.find(nums1[i]);
		for (int j = iter->second + 1; j < nums2.size(); j++) {
			if (nums2[j] > nums1[i]) {
				res[i] = nums2[j];
				break;
			}
		}
	}
	return res;
}




int main() {
	vector<int> nums1 = { 4,1,2 };
	vector<int> nums2 = { 1,3,4,2 };
	vector<int> res = nextGreaterElement(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}