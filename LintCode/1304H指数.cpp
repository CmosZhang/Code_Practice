#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//1304. H指数
//您的提交打败了 71.65% 的提交!
//这种方法并不是最简单的方法
int hIndex(vector<int> &citations) {
	// write your code here
	if (citations.empty()) {
		return 0;
	}
	int res = 0;
	int maxCit = citations[0];
	for (int i = 1; i < citations.size(); i++) {
		maxCit = max(citations[i], maxCit);
	}
	for (int i = maxCit; i >= 0; i--) {
		int count = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) {
				count++;
			}
		}
		if (count >= i) {
			res = max(i, res);//找到最大的就退出
			break;
		}
	}
	return res;
}

//网上的优秀答案
//利用后缀和的形式来做
//这个数组下标i对应的数表示大于等于i的数字出现的次数，这个数组可以O(n)求出
//然后从大到小枚举这些数，找到最大的满足条件的数即可
//时间复杂度为O(n)
int hIndex2(vector<int>& citations) {
	int n = citations.size();
	vector<int> num(n + 1, 0);//有一个小细节，只有N篇文章，
	//*假如数组最大值为6，长度为4,不用去考虑至少有6篇文章引用为6，因为不存在这种情况

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= n) {
			num[n] ++;//这就是对*处的代码展示
		}
		else {
			num[citations[i]] ++;
		}
	}
	int sum = 0;
	for (int i = n; i >= 0; i--) {
		sum += num[i];
		if (sum >= i)
			return i;
	}
	return 0;
}



int main() {
	vector<int> cit = { 3,0,6,1,5};
	cout << hIndex2(cit) << endl;
	system("pause");
	return 0;
}