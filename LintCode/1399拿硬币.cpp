#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//1399. ��Ӳ��
//̰�ĵ�˼·
//�������壺���ܰ���̰����ȡ��Ҳ���ǲ���ÿ��ȡ��ʱ�򶼱Ƚϵ�ǰ��ǰ������ֵȡ����ߡ�       
//��[1, 9999, 3, 4, 5], ��K = 2ʱ���������̰�ģ�ȡ���ľ���5, 4�� ��������       
//��Ҫ�����е����������һ�飬����ȷ�����͵������
//���´������̰�ĵ�˼·���½������
//int takeCoins(vector<int> &list, int k) {
//	// Write your code here
//	if (list.empty() || k == 0) {
//		return 0;
//	}
//	int res = 0;
//	int count = 1;
//	int len = list.size();
//	int left = 0;
//	int right = len - 1;
//	while (count <= k) {
//		int left_temp = left;
//		int right_temp = right;
//		if (list[left_temp] >= list[right_temp]) {
//			left++;
//			res += list[left_temp];
//		}
//		else {
//			right--;
//			res += list[right_temp];
//		}
//		count++;
//	}
//	return res;
//}

//�����ύ����� 95.36% ���ύ!
//������ֻ�ܴ�����߻����ұ���k�Σ����Խ���k�α�������ʼk�ζ���������ã�
//Ȼ���Ǵ������k-1�������ұ���1��......һֱ��ȫ��k�����Ǵ��ұ��ã�
//�ڴ˹����У�����һ�������������͵������
int takeCoins(vector<int> &list, int k) {
	// Write your code here
	if (list.empty() || k <= 0) {
		return 0;
	}
	int res = 0;
	int add = 0;
	for (int i = 0; i < k; i++) {
		add += list[i];
	}
	res = max(add, res);
	int idx = k - 1;
	int right = list.size() - 1;
	while (idx >= 0) {
		add -= list[idx];
		add += list[right];
		res = max(add, res);
		idx--;
		right--;
	}
	return res;
}

int main() {
	vector<int> nums = { 5,4,3,2,1 };
	int k = 2;
	cout << takeCoins(nums, k) << endl;
	system("pause");
	return 0;
}