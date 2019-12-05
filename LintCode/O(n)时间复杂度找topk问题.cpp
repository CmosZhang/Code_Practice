#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//ʵ���ϻ��ǿ�������ı��Ρ�
void InsertSort(int array[], int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int j = i;        
		while (j - 1 >= left && array[j] < array[j - 1]) { //j - 1 >= left��������Խ��   
			swap(array[j - 1], array[j]);  
			j--;        
		} 
	}
}

//�ҵ���λ������λ�����������±�
int FindMidMid(int array[], int left, int right) {
	if (right - left + 1 <= 5) {
		InsertSort(array, left, right);
		return (left + right) >> 1;
	}

	int j = left - 1;
	for (int i = left; i <= right; i += 5) {
		InsertSort(array, i, i + 4);
		swap(array[++j], array[i + 2]);
	}
	return FindMidMid(array, left, j);
}


int Partion(int array[], int left, int right, int pivot_index) {
	swap(array[pivot_index], array[right]);

	int j = left;
	for (int i = left; i < right; i++) {
		if (array[i] <= array[right]) {
			swap(array[j++], array[i]);
		}
	}
	swap(array[j], array[right]);
	return j;
}
	

void BFPRT(int array[], int left, int right, int k) {
	if (left == right) {
		return;
	}
	int pivot_index = FindMidMid(array, left, right);
	int index = Partion(array, left, right, pivot_index);
	int num = index - left + 1;
	if (num == k) {
		return;
	}
	else if (num > k) {
		BFPRT(array, left, index - 1, k);
	}
	else {
		BFPRT(array, index + 1, right, k - num);
	}
}

int main() {
	int k = 3;
    int array[] = { 1,4,2,3,6,5,-1,7,8,-10 };
	BFPRT(array, 0, 9, k);
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}