#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1039. ���ֿ�����
//�����ύ����� 64.75% ���ύ!
//����ķ���
int maxChunksToSorted(vector<int> &arr) {
	// write your code here
	if (arr.empty()) {
		return -1;
	}
	int len = arr.size();
	vector<int> maxOfLeft(len);
	vector<int> minOfRight(len);

	maxOfLeft[0] = arr[0];
	for (int i = 1; i < len; i++) {
		maxOfLeft[i] = max(maxOfLeft[i - 1], arr[i]);
	}

	minOfRight[len - 1] = arr[len - 1];
	for (int i = len - 2; i >= 0; i--) {
		minOfRight[i] = min(minOfRight[i + 1], arr[i]);
	}

	int res = 0;
	for (int i = 0; i < len - 1; i++) {
		if (maxOfLeft[i] <= minOfRight[i + 1])
			res++;
	}
	return res + 1;
}

//�ڶ��ַ��������������Ƚ����⣬�����е����ֵС������ĳ���
//˼·��
//ֻ��Ҫ�жϣ���ǰ�����ֵ�ǲ��Ǹ�index��ȡ�
//�����ȣ�˵����������Ѿ��߱�������Ԫ�ء�
//�������ȣ�˵��������װ���µ�ǰ���ֵ������Ӧ�����š�
//�����ύ����� 54.92% ���ύ!
int maxChunksToSorted2(vector<int> &arr) {
	// write your code here
	if (arr.empty()) {
		return -1;
	}
	int len = arr.size();
	int res = 0;
	int maxValue = arr[0];
	for (int i = 0; i < len; i++) {
		maxValue = max(maxValue, arr[i]);
		if (maxValue == i) {
			res++;
		}
	}
	return res;
}

int main() {
	vector<int> num;
	while (1) {
		int temp;
		cin >> temp;
		num.push_back(temp);
		char c;
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	cout << maxChunksToSorted2(num) << endl;
	system("pause");
	return 0;
}
