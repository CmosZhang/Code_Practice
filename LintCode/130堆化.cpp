#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//130. �ѻ�
//A[0]�Ƕѵĸ���������ÿ��A[i]��A [i * 2 + 1]��A[i]������Ӳ���A[i * 2 + 2]��A[i]���Ҷ���
//С���ѵĹ��죬����Ľڵ�i�Ǹ��ڵ�

//�����ύ����� 87.60% ���ύ!
void heapifyHelper(vector<int> &A, int i, int len) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < len) {
		if (A[left] < A[i]) {
			largest = left;
		}
	}

	if (right < len) {
		if (A[right] < A[largest]) {
			largest = right;
		}
	}

	if (largest != i) {
		swap(A[i], A[largest]);
		heapifyHelper(A, largest, len);
	}
}

void heapify(vector<int> &A) {
	// write your code here
	if (A.empty()) {
		return;
	}
	int len = A.size();
	for (int i = len / 2; i >= 0; i--)
		heapifyHelper(A, i, len);
}

int main() {
	vector<int> A = { 45,39,32,11,56,1};
	heapify(A);//�����󶥶�
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}