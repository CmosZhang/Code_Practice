#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>

using namespace std;

class MaxHeap {
private:
	int maxsize;//记录堆允许的最大容量
	int count;//记录堆中目前已插入元素的个数
	int *a;//堆用数组来表示，记录数组指针
	void shiftUp(int n);//向上交换元素
	void shiftDown(int n);//向下交换元素
public:
	MaxHeap(int size);//建立空堆
	MaxHeap(int *p, int n);//根据已有数组建立堆
	void add(int value);//插入元素
	int extractTop();//提取堆顶元素
	void sort();//排序
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
		add(a[i]);/*注意，这里是原位传递，最大堆是在原有数组空间上建立的，
				传递入堆的a[i]会对i位置及i之前的位置重新排序，但是不会影响i后面的数据；
				注意理论上的堆与实际的数据存储之间的关系*/
	}
}

void MaxHeap::add(int value) {
	if (count >= maxsize) {
		return;//这个堆中元素已经满了
	}
	a[count] = value;//把加入的元素放到最后面，然向上调整
	count++;
	shiftUp(count - 1);//保持堆的特性
}

void MaxHeap::shiftUp(int n) {
	if ((n > 0) && (a[n] > a[(n - 1) / 2])) {//递归出口，当子节点不大于父节点或者n等于0时，结束递归
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

//左右子节点都存在的情况，如果左右子节点的数都大于父节点，这个时候要向下调整。
//如果只有左节点存在，左子节点的数大于父节点，这个时候要向下调整。
void MaxHeap::shiftDown(int n) {
	if (n * 2 + 2 < count) {//左右节点都存在
		int temp;
		if ((a[n * 2 + 1] >= a[n * 2 + 2]) && (a[n] < a[n * 2 + 1])) {//调整左节点的值，放到父节点的位置
			temp = a[n];
			a[n] = a[n * 2 + 1];
			a[n * 2 + 1] = temp;
			shiftDown(n * 2 + 1);
		}
		if((a[n * 2 + 1] < a[n * 2 + 2]) && (a[n] < a[n * 2 + 2])) {//调整右节点的值，放到父节点的位置
			temp = a[n];
			a[n] = a[n * 2 + 2];
			a[n * 2 + 2] = temp;
			shiftDown(n * 2 + 2);
		}
	}
	if ((n * 2 + 1 == count - 1) && a[n] < a[n * 2 + 1]) {//只存在左节点
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
	int maxsize;//记录堆允许的最大容量
	int count;//记录堆中目前已插入元素的个数
	int *a;//堆用数组来表示，记录数组指针
	void shiftUp(int n);//向上交换元素
	void shiftDown(int n);//向下交换元素
public:
	MinHeap(int size);//建立空堆
	MinHeap(int *p, int n);//根据已有数组建立堆
	void add(int value);//插入元素
	void remove();//删除元素,删除元素只能从堆顶删除
	void removeValue(int value);//删除特定元素
	int extractTop();//提取堆顶元素
	void sort();//排序
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
		add(a[i]);/*注意，这里是原位传递，最大堆是在原有数组空间上建立的，
				传递入堆的a[i]会对i位置及i之前的位置重新排序，但是不会影响i后面的数据；
				注意理论上的堆与实际的数据存储之间的关系*/
	}
}

void MinHeap::add(int value) {
	if (count >= maxsize) {
		return;//这个堆中元素已经满了
	}
	a[count] = value;//把加入的元素放到最后面，然向上调整
	count++;
	shiftUp(count - 1);//保持堆的特性
}

void MinHeap::shiftUp(int n) {
	if ((n > 0) && (a[n] < a[(n - 1) / 2])) {//递归出口，当子节点不大于父节点或者n等于0时，结束递归
		int temp = a[n];//父节点大于子节点的时候，要调整堆
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
		shiftUp(i);//相当于index后面的元素重新添加了一遍
	}
	count--;
}

void MinHeap::print() {
	for (int i = 0; i < count; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//左右子节点都存在的情况，如果左右子节点的数都小于父节点，这个时候要向下调整。
//如果只有左节点存在，左子节点的数小于父节点，这个时候要向下调整。
void MinHeap::shiftDown(int n) {
	if (n * 2 + 2 < count) {//左右节点都存在
		int temp;
		if ((a[n * 2 + 1] <= a[n * 2 + 2]) && (a[n] > a[n * 2 + 1])) {//调整左节点的值，放到父节点的位置
			temp = a[n];
			a[n] = a[n * 2 + 1];
			a[n * 2 + 1] = temp;
			shiftDown(n * 2 + 1);
		}
		if ((a[n * 2 + 1] > a[n * 2 + 2]) && (a[n] > a[n * 2 + 2])) {//调整右节点的值，放到父节点的位置
			temp = a[n];
			a[n] = a[n * 2 + 2];
			a[n * 2 + 2] = temp;
			shiftDown(n * 2 + 2);
		}
	}
	if ((n * 2 + 1 == count - 1) && a[n] > a[n * 2 + 1]) {//只存在左节点
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


//堆排序
// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index的左子节点
	int right = 2 * index + 2;// index的右子节点

	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx])     maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx])     maxIdx = right;
	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}
}

// 堆排序
void heapSort(vector<int> &arr, int size)
{
	// 构建大根堆（从最后一个非叶子节点向上）
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}
	// 调整大根堆
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
		adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
	}
}



int main()
{
	srand((unsigned)time(NULL));
	MinHeap h(11);
	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 100;//产生100以内的随机数
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
