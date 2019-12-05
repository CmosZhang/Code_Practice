#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//���������㷨��Ϊһ�࣬��Ϊ������ʱ��Ƚ��������㷨
void outArray(vector<int>&nums);//�������
void BubbleSort(vector<int>&nums);//ð������
void SelectSort(vector<int>&nums);//ѡ������
void InsertionSort(vector<int>&nums);//��������
void ShellSort(vector<int>&nums);//ϣ������
void Merge(vector<int>&nums, int left, int mid, int right);
void MergeSort(vector<int>&nums);//�鲢����
int Partition(vector<int>&a, int left, int right);
void QuickSort(vector<int>&nums, int left, int right);//��������
void BuildMaxHeap(vector<int>&nums);
void AdjustHeap(vector<int> &nums, int p, int n);
void Swap(vector<int>&nums, int i, int j);
void HeapSort(vector<int>&nums,int n);//������

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
	for (int i = 0; i < len - 1; i++){ //ÿ��ѭ�����飬�ҳ���С��Ԫ�أ�����ǰ�棬ǰ��ļ�Ϊ����õ�
		mix = i; //������СԪ�ص��±�
		for (int j = i + 1; j < len; j++) //������������СԪ��������Ƚϣ���������С��Ԫ�ص��±�
			if (nums[j] < nums[mix])
				mix = j;
		//������������бȼ����Ԫ�ػ�С���ͽ���
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
	//�������øտ�ʼ������Ϊ���鳤�ȵ�һ��
	//gap�ɵ���
	for (int gap = len / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < len; i++) {
			temp = nums[i];
			int j;//ֱ�Ӳ�������
			for (j = i - gap; j > 0 && nums[j] > temp; j -= gap) {
				nums[j + gap] = nums[j];
			}
			nums[j + gap] = temp;
		}
	}
}


void Merge(vector<int>&nums, int left, int mid, int right) {
	vector<int> temp(right - left + 1);//����һ���µ����飬��ԭ����ӳ���ȥ 
	for (int m = left; m <= right; m++){
		temp[m - left] = nums[m];
	}

	int i = left, j = mid + 1;//i��j�ֱ�ָ�����������鿪ͷ����
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

void MergeSort(vector<int>&nums, int left, int right) {//�������϶��µĵݹ�
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


//�󶥶ѵĹ��죬�����i�Ǹ��ڵ�
void AdjustHeap(vector<int> &nums, int p, int n){
	int i, temp;
	temp = nums[p];
	for (i = 2 * p; i <= n; i *= 2) {   //��ȥ�����Һ��ӽ��
		//�ҵ��������ӽ��������
		if (i < n&&nums[i] < nums[i + 1])
			i++;
		//���ڵ�ͺ������Ľ����жϣ���������Ϊ����
		if (temp >= nums[i])
			break;
		//�����ڵ����ݱ�Ϊ���ģ���ԭ�������ݻ��Ƿ���temp�У�
		nums[p] = nums[i];    //���Ǻ��ӽ������ݸ������ǻὫ�������ƣ�Ϊ������ĵ��ṩλ��
		p = i;
	}
	//��������forѭ�����ҵ���p�����У����������ĵ㣬���Ǿͼ������ݵ��õ�p,ע�⣺p��ԭ�������Ѿ������ƶ���
	//��û���ҵ��������൱�ڶ���ֵ����
	//����
	nums[p] = temp;
}

void Swap(vector<int>&nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void HeapSort(vector<int>&nums, int n){
	int i;
	//���Ƚ���������ת��Ϊ�󶥶�
	for (i = n / 2; i > 0; i--)    //ע����������ȫ���������������Ǵ�һ����ǰ���죬���븸�ڵ�
		AdjustHeap(nums, i, n);
	//����󶥶��Ѿ�������ɣ�����������Ҫ����ÿ�ν�����Ԫ�ط������
	//Ȼ��ʣ��Ԫ�����¹���󶥶ѣ������Ԫ�ط���ʣ�����
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