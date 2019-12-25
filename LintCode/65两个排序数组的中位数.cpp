#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//65. 两个排序数组的中位数
//挑战
//时间复杂度为O(log n)
//您的提交打败了 7.20% 的提交!

//选择排序
void SelectSort(vector<int>&a, int n){ //选择排序
	int mix, temp;
	for (int i = 0; i<n - 1; i++){//每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
		mix = i; //假设最小元素的下标
		for (int j = i + 1; j<n; j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (a[j]<a[mix])
				mix = j;
		//若数组中真的有比假设的元素还小，就交换
		if (i != mix){
			temp = a[i];
			a[i] = a[mix];
			a[mix] = temp;
		}
	}
}


double findMedianSortedArrays(vector<int> &A, vector<int> &B){
	// write your code here
	int n = B.size();
	for (int i = 0; i < n; i++){
		A.push_back(B[i]);
	}

	int m = A.size();
	int left = 0, right = m;

	//选择排序
	SelectSort(A, m);
	double res;
	//找中位数
	int mid = (left + right) / 2;
	//cout << mid << endl;
	if (m % 2 == 0){
		//double res = (A[mid] + A[mid - 1]) / 2;
		return res = (A[mid] + A[mid - 1]) / 2.0;
	}
	else{
		return A[mid];
	}
}

int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
	if (i >= nums1.size()) return nums2[j + k - 1];
	if (j >= nums2.size()) return nums1[i + k - 1];
	if (k == 1) return min(nums1[i], nums2[j]);
	int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
	int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
	if (midVal1 < midVal2) {
		return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
	}
	else {
		return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
	}
}

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	int left = (m + n + 1) / 2, right = (m + n + 2) / 2;
	return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}



int main()
{
	vector<int>A = { 1,2,3,4,5,6 };
	vector<int>B = { 2,3,4,5 };

	double res = findMedianSortedArrays(A, B);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	
	cout << endl;
	cout << res << endl;
	system("pause");
	return 0;
}