#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1424. �����е��ɽ��
//�����ύ����� 100.00% ���ύ!
//
int longestMountain(vector<int> &A) {
	// write your code here
	if (A.empty() || A.size() < 3) {
		return 0;
	}
	int len = A.size();
	int left = 0;
	int right = 0;
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (right > 0 && A[i - 1] < A[i] || A[i - 1] == A[i]) {
			left = 0;
			right = 0;
		}
		if (A[i - 1] < A[i]) {
			left++;
		}
		if (A[i - 1] > A[i]) {
			right++;
		}
		if (left > 0 && right > 0 && right + left + 1 > res) {
			res = left + right + 1;
		}
	}
	return res;
}


//����Ĵ�
//���������Ƚ�����⣬ʹ�ö�̬�滮�ķ���
//˼·����������ֻҪ������ȷ����A[i]Ϊβ�˵�����������飬
//��A[i]Ϊ��ʼ����ݼ�������
//�����ϲ�����һ��ɽ��
//�����ύ����� 100.00% ���ύ!
int longestMountain2(vector<int> &A) {
	// write your code here
	if (A.empty() || A.size() < 3) {
		return 0;
	}
	int len = A.size();
	//left[i]��¼��A[i]Ϊ��β�������������
	vector<int> left(len, 1);
	//right[i]��¼��A[i]Ϊ��ʼ����ݼ�������
	vector<int> right(len, 1);

	//�������ң�
	for (int i = 1; i < len; i++) {
		if (A[i - 1] < A[i]) {
			left[i] = left[i - 1] + 1;
		}
	}
	//��������
	for (int i = len - 2; i >= 0; i--) {
		if (A[i] > A[i + 1]) {
			right[i] = right[i + 1] + 1;
		}
	}

	//�ϲ�
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (left[i] > 1 && right[i] > 1) {
			res = max(res, left[i] + right[i] - 1);//�м��ɽ������������
		}
	}
	return res;
}


int main() {
	vector<int> nums;
	char c;
	int temp;
	while (1) {
		cin >> temp;
		nums.push_back(temp);
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	cout << longestMountain2(nums) << endl;
	system("pause");
	return 0;
}