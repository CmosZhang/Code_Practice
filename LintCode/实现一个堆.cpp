#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>

using namespace std;

class MaxHeap {
private:
	int maxsize;//��¼��������������
	int count;//��¼����Ŀǰ�Ѳ���Ԫ�صĸ���
	int *a;//������������ʾ����¼����ָ��
	void shiftUp(int n);//���Ͻ���Ԫ��
	void shiftDown(int n);//���½���Ԫ��
public:
	MaxHeap(int size);//�����ն�
	MaxHeap(int *p, int n);//�����������齨����
	void add(int value);//����Ԫ��
	int extractTop();//��ȡ�Ѷ�Ԫ��
	void sort();//����
	~MaxHeap();
};


MaxHeap::MaxHeap(int size){
	count = 0;
	maxsize = size;
	a = new int[size];
}

MaxHeap::MaxHeap(int *pa, int n) {
	a = pa;
	maxsize = n;
	count = 0;
	for (int i = 0; i < n; i++) {
		add(a[i]);/*ע�⣬������ԭλ���ݣ���������ԭ������ռ��Ͻ����ģ�
				������ѵ�a[i]���iλ�ü�i֮ǰ��λ���������򣬵��ǲ���Ӱ��i��������ݣ�
				ע�������ϵĶ���ʵ�ʵ����ݴ洢֮��Ĺ�ϵ*/
	}
}

void MaxHeap::add(int value) {
	if (count >= maxsize) {
		return;//�������Ԫ���Ѿ�����
	}
	a[count] = value;//�Ѽ����Ԫ�طŵ�����棬Ȼ���ϵ���
	count++;
	shiftUp(count - 1);//���ֶѵ�����
}

void MaxHeap::shiftUp(int n) {
	if ((n > 0) && (a[n] > a[(n - 1) / 2])) {//�ݹ���ڣ����ӽڵ㲻���ڸ��ڵ����n����0ʱ�������ݹ�
		int temp = a[n];
		a[n] = a[(n - 1) / 2];
		a[(n - 1) / 2] = temp;
		shiftUp((n - 1) / 2);
	}
}

int MaxHeap::extractTop() {
	int val = a[0];
	a[0] = a[count - 1];
	count--;
	shiftDown(0);
	return val;
}

//�����ӽڵ㶼���ڵ��������������ӽڵ���������ڸ��ڵ㣬���ʱ��Ҫ���µ�����
//���ֻ����ڵ���ڣ����ӽڵ�������ڸ��ڵ㣬���ʱ��Ҫ���µ�����
void MaxHeap::shiftDown(int n) {
	if (n * 2 + 2 < count) {//���ҽڵ㶼����
		int temp;
		if ((a[n * 2 + 1] >= a[n * 2 + 2]) && (a[n] < a[n * 2 + 1])) {//������ڵ��ֵ���ŵ����ڵ��λ��
			temp = a[n];
			a[n] = a[n * 2 + 1];
			a[n * 2 + 1] = temp;
			shiftDown(n * 2 + 1);
		}
		if((a[n * 2 + 1] < a[n * 2 + 2]) && (a[n] < a[n * 2 + 2])) {//�����ҽڵ��ֵ���ŵ����ڵ��λ��
			temp = a[n];
			a[n] = a[n * 2 + 2];
			a[n * 2 + 2] = temp;
			shiftDown(n * 2 + 2);
		}
	}
	if ((n * 2 + 1 == count - 1) && a[n] < a[n * 2 + 1]) {//ֻ������ڵ�
		int temp;
		temp = a[n];
		a[n] = a[n * 2 + 1];
		a[n * 2 + 1] = temp;
		shiftDown(n * 2 + 1);
	}
}

void MaxHeap::sort() {
	int n = count;
	for (int i = n - 1; i >= 0; i--) {
		a[i] = extractTop();
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

MaxHeap::~MaxHeap() {
	delete[]a;
}



class MinHeap {
private:
	int maxsize;//��¼��������������
	int count;//��¼����Ŀǰ�Ѳ���Ԫ�صĸ���
	int *a;//������������ʾ����¼����ָ��
	void shiftUp(int n);//���Ͻ���Ԫ��
	void shiftDown(int n);//���½���Ԫ��
public:
	MinHeap(int size);//�����ն�
	MinHeap(int *p, int n);//�����������齨����
	void add(int value);//����Ԫ��
	void remove();//ɾ��Ԫ��,ɾ��Ԫ��ֻ�ܴӶѶ�ɾ��
	void removeValue(int value);//ɾ���ض�Ԫ��
	int extractTop();//��ȡ�Ѷ�Ԫ��
	void sort();//����
	void print();
	~MinHeap();
};


MinHeap::MinHeap(int size) {
	count = 0;
	maxsize = size;
	a = new int[size];
}

MinHeap::MinHeap(int *pa, int n) {
	a = pa;
	maxsize = n;
	count = 0;
	for (int i = 0; i < n; i++) {
		add(a[i]);/*ע�⣬������ԭλ���ݣ���������ԭ������ռ��Ͻ����ģ�
				������ѵ�a[i]���iλ�ü�i֮ǰ��λ���������򣬵��ǲ���Ӱ��i��������ݣ�
				ע�������ϵĶ���ʵ�ʵ����ݴ洢֮��Ĺ�ϵ*/
	}
}

void MinHeap::add(int value) {
	if (count >= maxsize) {
		return;//�������Ԫ���Ѿ�����
	}
	a[count] = value;//�Ѽ����Ԫ�طŵ�����棬Ȼ���ϵ���
	count++;
	shiftUp(count - 1);//���ֶѵ�����
}

void MinHeap::shiftUp(int n) {
	if ((n > 0) && (a[n] < a[(n - 1) / 2])) {//�ݹ���ڣ����ӽڵ㲻���ڸ��ڵ����n����0ʱ�������ݹ�
		int temp = a[n];//���ڵ�����ӽڵ��ʱ��Ҫ������
		a[n] = a[(n - 1) / 2];
		a[(n - 1) / 2] = temp;
		shiftUp((n - 1) / 2);
	}
}

int MinHeap::extractTop() {
	int val = a[0];
	a[0] = a[count - 1];
	count--;
	shiftDown(0);
	return val;
}

void MinHeap::remove() {
	int val = a[0];
	a[0] = a[count - 1];
	count--;
	shiftDown(0);
}

void MinHeap::removeValue(int value) {
	bool flag = false;
	int index = 0;
	for (int i = 0; i < count; i++) {
		if (a[i] == value) {
			flag = true;
			index = i;
			break;
		}
	}
	if (!flag)return;
	for (int i = index; i < count - 1; i++) {
		swap(a[i], a[i + 1]);
		shiftUp(i);//�൱��index�����Ԫ�����������һ��
	}
	count--;
}

void MinHeap::print() {
	for (int i = 0; i < count; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//�����ӽڵ㶼���ڵ��������������ӽڵ������С�ڸ��ڵ㣬���ʱ��Ҫ���µ�����
//���ֻ����ڵ���ڣ����ӽڵ����С�ڸ��ڵ㣬���ʱ��Ҫ���µ�����
void MinHeap::shiftDown(int n) {
	if (n * 2 + 2 < count) {//���ҽڵ㶼����
		int temp;
		if ((a[n * 2 + 1] <= a[n * 2 + 2]) && (a[n] > a[n * 2 + 1])) {//������ڵ��ֵ���ŵ����ڵ��λ��
			temp = a[n];
			a[n] = a[n * 2 + 1];
			a[n * 2 + 1] = temp;
			shiftDown(n * 2 + 1);
		}
		if ((a[n * 2 + 1] > a[n * 2 + 2]) && (a[n] > a[n * 2 + 2])) {//�����ҽڵ��ֵ���ŵ����ڵ��λ��
			temp = a[n];
			a[n] = a[n * 2 + 2];
			a[n * 2 + 2] = temp;
			shiftDown(n * 2 + 2);
		}
	}
	if ((n * 2 + 1 == count - 1) && a[n] > a[n * 2 + 1]) {//ֻ������ڵ�
		int temp;
		temp = a[n];
		a[n] = a[n * 2 + 1];
		a[n * 2 + 1] = temp;
		shiftDown(n * 2 + 1);
	}
}

void MinHeap::sort() {
	int n = count;
	for (int i = n - 1; i >= 0; i--) {
		a[i] = extractTop();
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

MinHeap::~MinHeap() {
	delete[]a;
}


//������
// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index�����ӽڵ�
	int right = 2 * index + 2;// index�����ӽڵ�

	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx])     maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx])     maxIdx = right;
	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}
}

// ������
void heapSort(vector<int> &arr, int size)
{
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}
	// ���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
	}
}



int main()
{
	srand((unsigned)time(NULL));
	MinHeap h(11);
	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 100;//����100���ڵ������
		cout << temp << endl;
		h.add(temp);
	}
	h.add(34);
	h.print();
	//int val = h.extractTop();
	h.remove();
	h.print();
	h.removeValue(34);
	h.print();
	system("pause");
	return 0;
}
