#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//以下排序算法归为一类，称为非线性时间比较类排序算法
void outArray(vector<int>&nums);//输出数组
void BubbleSort(vector<int>&nums);//冒泡排序
void SelectSort(vector<int>&nums);//选择排序
void InsertionSort(vector<int>&nums);//插入排序
void ShellSort(vector<int>&nums);//希尔排序
void Merge(vector<int>&nums, int left, int mid, int right);
void MergeSort(vector<int>&nums);//归并排序
int Partition(vector<int>&a, int left, int right);
void QuickSort(vector<int>&nums, int left, int right);//快速排序
void BuildMaxHeap(vector<int>&nums);
void AdjustHeap(vector<int> &nums, int p, int n);
void Swap(vector<int>&nums, int i, int j);
void HeapSort(vector<int>&nums,int n);//堆排序

void outArray(vector<int>&nums) {
	if (nums.empty()) {
		return;
	}
	for (int i = 0; i < nums.size() - 1; i++) {
		cout << nums[i] << " ";
	}
	cout << nums[nums.size() - 1] << endl;
}

void BubbleSort(vector<int>&nums) {
	if (nums.empty()) {
		return;
	}
	int temp;
	int len = nums.size();
	for (int j = 0; j < len - 1; j++){
		for (int k = 0; k < len - 1 - j; k++){
			if (nums[k] > nums[k + 1]){
				temp = nums[k];
				nums[k] = nums[k + 1];
				nums[k + 1] = temp;
			}
		}
	}
}

void SelectSort(vector<int>&nums) {
	if (nums.empty()) {
		return;
	}
	int mix, temp;
	int len = nums.size();
	for (int i = 0; i < len - 1; i++){ //每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
		mix = i; //假设最小元素的下标
		for (int j = i + 1; j < len; j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (nums[j] < nums[mix])
				mix = j;
		//若数组中真的有比假设的元素还小，就交换
		if (i != mix){
			temp = nums[i];
			nums[i] = nums[mix];
			nums[mix] = temp;
		}
	}
}

void InsertionSort(vector<int>&nums) {
	if (nums.empty()) {
		return;
	}
	int len = nums.size();
	int preIndex, cur;
	for (int i = 1; i < len; i++) {
		preIndex = i - 1;
		cur = nums[i];
		while (preIndex >= 0 && nums[preIndex] > cur) {
			nums[preIndex + 1] = nums[preIndex];
			preIndex--;
		}
		nums[preIndex + 1] = cur;
	}
}

void ShellSort(vector<int>&nums) {
	if (nums.empty()) {
		return;
	}
	int len = nums.size();
	int temp;
	//这里设置刚开始的增量为数组长度的一半
	//gap可调节
	for (int gap = len / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < len; i++) {
			temp = nums[i];
			int j;//直接插入排序
			for (j = i - gap; j > 0 && nums[j] > temp; j -= gap) {
				nums[j + gap] = nums[j];
			}
			nums[j + gap] = temp;
		}
	}
}


void Merge(vector<int>&nums, int left, int mid, int right) {
	vector<int> temp(right - left + 1);//开辟一个新的数组，将原数组映射进去 
	for (int m = left; m <= right; m++){
		temp[m - left] = nums[m];
	}

	int i = left, j = mid + 1;//i和j分别指向两个子数组开头部分
	for (int k = left; k <= right; k++){
		if (i > mid){
			nums[k] = temp[j - left];
			j++;
		}
		else if (j > right){
			nums[k] = temp[i - left];
			i++;
		}
		else if (temp[i - left] < temp[j - left]){
			nums[k] = temp[i - left];
			i++;
		}
		else{
			nums[k] = temp[j - left];
			j++;
		}
	}
}

void MergeSort(vector<int>&nums, int left, int right) {//采用自上而下的递归
	if (nums.empty()|| left >= right) {
		return;
	}
	int len = nums.size();
	int mid = (right - left) / 2 + left;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);
	Merge(nums, left, mid, right);
}


int Partition(vector<int>&a, int left, int right){
	int temp = a[left];
	while (right > left){
		while (left < right&&a[right] >= temp){
			right--;
		}
		a[left] = a[right];
		while (left < right&&a[left] <= temp){
			left++;
		}
		a[right] = a[left];
	}
	a[right] = temp;
	return left;
}

void QuickSort(vector<int>&nums, int left, int right){
	if (left < right){
		int pos = Partition(nums, left, right);
		QuickSort(nums, left, pos - 1);
		QuickSort(nums, pos + 1, right);
	}
}


//大顶堆的构造，传入的i是父节点
void AdjustHeap(vector<int> &nums, int p, int n){
	int i, temp;
	temp = nums[p];
	for (i = 2 * p; i <= n; i *= 2) {   //逐渐去找左右孩子结点
		//找到两个孩子结点中最大的
		if (i < n&&nums[i] < nums[i + 1])
			i++;
		//父节点和孩子最大的进行判断，调整，变为最大堆
		if (temp >= nums[i])
			break;
		//将父节点数据变为最大的，将原来的数据还是放在temp中，
		nums[p] = nums[i];    //若是孩子结点的数据更大，我们会将数据上移，为他插入的点提供位置
		p = i;
	}
	//当我们在for循环中找到了p子树中，满足条件的点，我们就加入数据到该点p,注意：p点原来数据已经被上移动了
	//若没有找到，就是相当于对其值不变
	//插入
	nums[p] = temp;
}

void Swap(vector<int>&nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void HeapSort(vector<int>&nums, int n){
	int i;
	//首先将无序数列转换为大顶堆
	for (i = n / 2; i > 0; i--)    //注意由于是完全二叉树，所以我们从一半向前构造，传入父节点
		AdjustHeap(nums, i, n);
	//上面大顶堆已经构造完成，我们现在需要排序，每次将最大的元素放入最后
	//然后将剩余元素重新构造大顶堆，将最大元素放在剩余最后
	for (i = n; i > 1; i--){
		Swap(nums, 1, i);
		AdjustHeap(nums, 1, i - 1);
	}
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
	outArray(nums);
	HeapSort(nums, nums.size() - 1);
	outArray(nums);
	system("pause");
	return 0;
}