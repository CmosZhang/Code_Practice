#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void Swap(vector<int>&A, int i, int j);//交换数据元素
void heapifyHelper(vector<int> &A, int i, int len);//小顶堆的构造，调整堆中数据
void heapify(vector<int> &A);//构建小顶堆
void HeapSortDes(vector<int>&A);//利用小顶堆进行降序排序
void AdjustHeap(vector<int>&A, int i, int len);//大顶堆的构造，调整堆中数据
void heapify2(vector<int> &A);//构建大顶堆
void HeapSortAsc(vector<int>&A); //利用大顶堆进行降序排序

void Swap(vector<int>&A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//A[0]是堆的根，并对于每个A[i]，A [i * 2 + 1]是A[i]的左儿子并且A[i * 2 + 2]是A[i]的右儿子
//小顶堆的构造，传入的节点i是父节点
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

void HeapSortDes(vector<int>&A) {//降序排序
	int n = A.size();
	for (int i = n; i > 0; i--) {
		Swap(A, 0, i - 1);
		heapifyHelper(A, 0, i - 1);
	}
}

//构造大顶堆
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
		AdjustHeap(A, i, n);//大顶堆构造完成
	}
}

void HeapSortAsc(vector<int>&A) {//升序排序
	int n = A.size();
	for (int i = n; i > 0; i--) {
		Swap(A, 0, i - 1);
		AdjustHeap(A, 0, i - 1);
	}
}

int main() {
	vector<int> A = { 45,39,32,11,56,1,25,43 };
	heapify(A);//构建小顶堆
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	HeapSortDes(A);//利用小顶堆排序
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	//heapify2(A);//构建大顶堆
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	//HeapSortAsc(A);//利用大顶堆排序
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	system("pause");
	return 0;
}