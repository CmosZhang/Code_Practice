#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void Swap(vector<int>&A, int i, int j);//��������Ԫ��
void heapifyHelper(vector<int> &A, int i, int len);//С���ѵĹ��죬������������
void heapify(vector<int> &A);//����С����
void HeapSortDes(vector<int>&A);//����С���ѽ��н�������
void AdjustHeap(vector<int>&A, int i, int len);//�󶥶ѵĹ��죬������������
void heapify2(vector<int> &A);//�����󶥶�
void HeapSortAsc(vector<int>&A); //���ô󶥶ѽ��н�������

void Swap(vector<int>&A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//A[0]�Ƕѵĸ���������ÿ��A[i]��A [i * 2 + 1]��A[i]������Ӳ���A[i * 2 + 2]��A[i]���Ҷ���
//С���ѵĹ��죬����Ľڵ�i�Ǹ��ڵ�
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
	if (A.empty()) {
		return;
	}
	int len = A.size();
	for (int i = len / 2; i >= 0; i--)
		heapifyHelper(A, i, len);
}

void HeapSortDes(vector<int>&A) {//��������
	int n = A.size();
	for (int i = n; i > 0; i--) {
		Swap(A, 0, i - 1);
		heapifyHelper(A, 0, i - 1);
	}
}

//����󶥶�
void AdjustHeap(vector<int>&A, int i, int len) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < len) {
		if (A[left] > A[i]) {
			largest = left;
		}
	}

	if (right < len) {
		if (A[right] > A[largest]) {
			largest = right;
		}
	}

	if (largest != i) {
		swap(A[i], A[largest]);
		AdjustHeap(A, largest, len);
	}
}


void heapify2(vector<int> &A) {
	if (A.empty()) {
		return;
	}
	int n = A.size();
	for (int i = n / 2; i >= 0; i--) {
		AdjustHeap(A, i, n);//�󶥶ѹ������
	}
}

void HeapSortAsc(vector<int>&A) {//��������
	int n = A.size();
	for (int i = n; i > 0; i--) {
		Swap(A, 0, i - 1);
		AdjustHeap(A, 0, i - 1);
	}
}

int main() {
	vector<int> A = { 45,39,32,11,56,1,25,43 };
	heapify(A);//����С����
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	HeapSortDes(A);//����С��������
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	//heapify2(A);//�����󶥶�
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	//HeapSortAsc(A);//���ô󶥶�����
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	system("pause");
	return 0;
}