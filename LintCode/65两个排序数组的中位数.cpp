#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//65. ���������������λ��
//��ս
//ʱ�临�Ӷ�ΪO(log n)
//�����ύ����� 7.20% ���ύ!

//ѡ������
void SelectSort(vector<int>&a, int n){ //ѡ������
	int mix, temp;
	for (int i = 0; i<n - 1; i++){//ÿ��ѭ�����飬�ҳ���С��Ԫ�أ�����ǰ�棬ǰ��ļ�Ϊ����õ�
		mix = i; //������СԪ�ص��±�
		for (int j = i + 1; j<n; j++) //������������СԪ��������Ƚϣ���������С��Ԫ�ص��±�
			if (a[j]<a[mix])
				mix = j;
		//������������бȼ����Ԫ�ػ�С���ͽ���
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

	//ѡ������
	SelectSort(A, m);
	double res;
	//����λ��
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