#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1075.�˻�С��K��������
//ʹ�ñ������ķ������ⲻ����򵥵ķ���
//�����ύ����� 100.00% ���ύ!
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty()) {
		return 0;
	}
	int len = nums.size();
	
	int res = 0;
	for (int i = 0; i < len; i++) {
		int left = i;
		int right = len - 1;
		int mul = 1;
		while (left <= right) {
			mul = mul * nums[left];
			if (mul < k) {
				res++;
				left++;
			}
			else {
				break;
			}
		}
	}
	return res;
}

//����Ĵ�
//ʱ�临�Ӷ�ΪO(n)
//˼·��
//ά��һ���������ڣ�leftΪ���ڵ���˵㣬i����̽����һ������left��i��ɵĻ�������Ϊ[left, i]
//�����ǰ�����е��������ĳ˻� >= k�� ˵�����ڲ�����������( < k), 
//���leftָ�����˵�����Ӵ�����ȥ������ӳ�ڴ��ڳ˻���Ӧ���ǳ���Ҫɾ�����������
//Ȼ��left++��һֱ�ظ���ȥֱ�������ٴ����������������ҵ���һ���µĴ��ڣ�
//���ڵĳ��Ⱦ��ǵ�ǰ���������������������������
//���ڳ����� i - left + 1����ʾ��

int numSubarrayProductLessThanK2(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty()) {
		return 0;
	}
	int len = nums.size();
	int res = 0;
	int left = 0;
	int product = 1;
	for (int i = 0; i < len; i++) {
		product *= nums[i];
		while (product >= k) {
			product /= nums[left++];
		}
		res += i - left + 1;
	}
	return res;
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
	int k;
	cin >> k;
	cout << numSubarrayProductLessThanK2(nums, k) << endl;
	system("pause");
	return 0;
}