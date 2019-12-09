#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

//double类型数据排序，要求时间复杂度为O(n)
//O(n)复杂度的排序算法主要是计数排序、基数排序和桶排序。
//采用基数排序的方式求解这个问题

void RadixSort(vector<double> &nums) {
	if (nums.empty()) {
		return;
	}
	int n = nums.size();
	vector<long long> t(n), a(n);

	for (int i = 0; i < n; i++)
		a[i] = *(long long*)(&nums[i]);//将数组中每个元素地址类型转换成long long类型在取元素值。

	//将double类型数组分为4部分
	int groupLength = 16;
	int bitLength = 64;
	int len = 1 << groupLength;

	vector<int> count(len), pref(len);

	int groups = bitLength / groupLength;
	int mask = len - 1;
	int negatives = 0, positives = 0;

	for (int c = 0, shift = 0; c < groups; c++, shift += groupLength) {
		// 重置数组
		fill(count.begin(), count.end(), 0);

		// 计算元素属于哪一个段
		for (int i = 0; i < n; i++) {
			++count[(a[i] >> shift) & mask];

			// 额外考虑负数问题，记录负数的个数
			if (c == 0 && a[i] < 0)
				++negatives;
		}
		if (c == 0)
			positives = n - negatives;

		// 计算每一段的起始位置
		pref[0] = 0;
		for (int i = 1; i < len; i++)
			pref[i] = pref[i - 1] + count[i - 1];

		// 将数组中的数复制到临时数组t中
		for (int i = 0; i < n; i++) {
			int index = pref[(a[i] >> shift) & mask]++;
			if (c == groups - 1) {//如果是负数，则从大向小排列，索引逆序
				if (a[i] < 0)
					index = n - index - 1;
				else
					index += negatives;
			}
			t[index] = a[i];
		}

		//将临时数组中的数复制到原数组
		if (c != groups - 1) {
			for (int j = 0; j < n; j++)
				a[j] = t[j];
		}
	}

	// 返回到原double类型的数组中
	for (int i = 0; i < n; i++)
		nums[i] = *(double*)(&t[i]);
}




int main()
{
	vector<double> input = { 3.23,6.854,12.8,79.5,-2.3,1.0,0.23,-0.9 };
	RadixSort(input);
	for (int i = 0; i < input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}