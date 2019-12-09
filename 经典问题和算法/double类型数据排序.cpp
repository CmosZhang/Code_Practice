#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

//double������������Ҫ��ʱ�临�Ӷ�ΪO(n)
//O(n)���Ӷȵ������㷨��Ҫ�Ǽ������򡢻��������Ͱ����
//���û�������ķ�ʽ����������

void RadixSort(vector<double> &nums) {
	if (nums.empty()) {
		return;
	}
	int n = nums.size();
	vector<long long> t(n), a(n);

	for (int i = 0; i < n; i++)
		a[i] = *(long long*)(&nums[i]);//��������ÿ��Ԫ�ص�ַ����ת����long long������ȡԪ��ֵ��

	//��double���������Ϊ4����
	int groupLength = 16;
	int bitLength = 64;
	int len = 1 << groupLength;

	vector<int> count(len), pref(len);

	int groups = bitLength / groupLength;
	int mask = len - 1;
	int negatives = 0, positives = 0;

	for (int c = 0, shift = 0; c < groups; c++, shift += groupLength) {
		// ��������
		fill(count.begin(), count.end(), 0);

		// ����Ԫ��������һ����
		for (int i = 0; i < n; i++) {
			++count[(a[i] >> shift) & mask];

			// ���⿼�Ǹ������⣬��¼�����ĸ���
			if (c == 0 && a[i] < 0)
				++negatives;
		}
		if (c == 0)
			positives = n - negatives;

		// ����ÿһ�ε���ʼλ��
		pref[0] = 0;
		for (int i = 1; i < len; i++)
			pref[i] = pref[i - 1] + count[i - 1];

		// �������е������Ƶ���ʱ����t��
		for (int i = 0; i < n; i++) {
			int index = pref[(a[i] >> shift) & mask]++;
			if (c == groups - 1) {//����Ǹ�������Ӵ���С���У���������
				if (a[i] < 0)
					index = n - index - 1;
				else
					index += negatives;
			}
			t[index] = a[i];
		}

		//����ʱ�����е������Ƶ�ԭ����
		if (c != groups - 1) {
			for (int j = 0; j < n; j++)
				a[j] = t[j];
		}
	}

	// ���ص�ԭdouble���͵�������
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