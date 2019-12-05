#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

void insertionSort(vector<int>&arr) {
	int len = arr.size();
	int preIndex, current;
	for (int i = 1; i < len; i++) {
		preIndex = i - 1;
		current = arr[i];
		while (preIndex >= 0 && arr[preIndex] > current) {
			arr[preIndex + 1] = arr[preIndex];
			preIndex--;
		}
		arr[preIndex + 1] = current;
	}
}

vector<int> bucketSort(vector<int>&num, int bucketSize) {
	if (num.empty()) {
		return num;
	}
	int minValue = num[0];
	int maxValue = num[0];
	for (int i = 1; i < num.size(); i++) {
		maxValue = max(num[i], maxValue);
		minValue = min(num[i], minValue);
	}
	int DEFAULT_BUCKET_SIZE = 5;            // 设置桶的默认数量为5
	bucketSize = bucketSize || DEFAULT_BUCKET_SIZE;
	int bucketCount = floor((maxValue - minValue) / bucketSize) + 1;
	//vector<int> buckets(bucketCount, 0);
	vector<vector<int>> buckets(bucketCount, vector<int>());

	// 利用映射函数将数据分配到各个桶中
	for (int i = 0; i < num.size(); i++) {
		buckets[floor((num[i] - minValue) / bucketSize)].push_back(num[i]);
	}

	//num.size() = 0;
	vector<int> arr;
	for (int i = 0; i < buckets.size(); i++) {
		insertionSort(buckets[i]);                      // 对每个桶进行排序，这里使用了插入排序
		for (int j = 0; j < buckets[i].size(); j++) {
			arr.push_back(buckets[i][j]);
		}
	}
	return arr;
}

//对于一个字符串数组来说，使用桶排序


int main() {
	vector<int> num = { 1,3,4,2,6,7,8,3,4,9 };
	vector<int> res = bucketSort(num, 6);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	system("pause");
	return 0;
}